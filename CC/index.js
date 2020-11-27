const app = require("express")();
const bodyParser = require("body-parser");
var mkdirp = require("mkdirp");
const fs = require("fs");
const port = 8080;

app.use(bodyParser.json());

app.post("/", (req, res) => {
  const data = req.body;
  const path = `../Task/${data.name
    .replace(/"/g, `'`)
    .replace(/!/g, ``)
    .replace(/\//g, `-`)}`;
  mkdirp(path, function (err) {});
  let tests = [];

  for (let i = 0; i < data.tests.length; i++) {
    let test = {
      input: data.tests[i].input,
      output: data.tests[i].output,
      index: i,
      active: true,
    };
    tests.push(test);
  }
  fs.copyFile(
    `../Template/solution.template`,
    `${path}/solution.cpp`,
    function (err) {}
  );
  obj = {
    tests: tests,
    name: data.name.replace(/"/g, `'`).replace(/!/g, ``).replace(/\//g, `-`),
    group: data.group.replace(/"/g, `'`).replace(/!/g, ``).replace(/\//g, `-`),
    isInteractive: data.interactive,
    timeLimit: data.timeLimit !== null ? data.timeLimit : 5000,
    truncateLongTest: false,
    useGeneration: false,
    useLocalChecker: false,
    url: data.url,
    numTest: 0,
    genParameters: null,
    knowGenAns: false,
    checker: "token_checker",
    stopAtWrongAnswer: false,
  };
  fs.writeFile(`${path}/config.json`, JSON.stringify(obj), function (err) {});
  res.sendStatus(200);
});

app.listen(port, (err) => {
  if (err) {
    console.error(err);
    process.exit(1);
  }
  console.log(`Listening on port ${port}`);
});
