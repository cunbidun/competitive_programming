const app = require("express")();
const bodyParser = require("body-parser");
var mkdirp = require("mkdirp");
const fs = require("fs");

const PORT = 8080;

app.use(bodyParser.json());

function reformat(s) {
  return s.replace(/"/g, `'`).replace(/!/g, ``).replace(/\//g, `-`);
}

app.post("/", (req, res) => {
  console.log(req.body);
  const data = req.body;
  const path = `../Task/${reformat(data.name)}`;
  mkdirp(path, function () {});
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
    function () {}
  );
  obj = {
    tests: tests,
    name: reformat(data.name),
    group: reformat(data.group),
    interactive: false,
    timeLimit: data.timeLimit !== null ? data.timeLimit : 5000,
    truncateLongTest: false,
    useGeneration: false,
    url: data.url,
    numTest: 0,
    genParameters: "",
    knowGenAns: false,
    checker: "token_checker",
    stopAtWrongAnswer: false,
    compact: false,
    generatorSeed: "",
    hideAcceptedTest: false,
  };
  fs.writeFile(`${path}/config.json`, JSON.stringify(obj), function () {});
  res.sendStatus(200);
});

app.listen(PORT, (err) => {
  if (err) {
    console.error(err);
    process.exit(1);
  }
  console.log(`Listening on PORT ${PORT}`);
});
