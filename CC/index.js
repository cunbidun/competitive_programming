const app = require("express")();
const bodyParser = require("body-parser");
var mkdirp = require("mkdirp");
const fs = require("fs");
const { json } = require("express");

const PORT = 8080;

app.use(bodyParser.json());

function reformat(s) {
  return s.replace(/"/g, `'`).replace(/!/g, ``).replace(/\//g, `-`);
}

app.post("/", async (req, res) => {
  console.log(req.body);
  const data = req.body;
  const path = `../Task/${reformat(data.name)}`;

  await mkdirp(path, (err) => {
    if (err) {
      console.log("mkdir failed:", err);
      return;
    }
  });

  let cnt = 0;
  let tests = data.tests.map((e) => ({
    input: e.input,
    output: e.output,
    index: cnt++,
    active: true,
  }));

  taskData = {
    tests: tests,
    name: reformat(data.name),
    group: reformat(data.group),
    timeLimit: data.timeLimit !== null ? data.timeLimit : 5000,
    url: data.url,
  };

  fs.copyFile(
    `../Template/solution.template`,
    `${path}/solution.cpp`,
    (err) => {
      if (err) {
        console.log("File copy failed:", err);
        return;
      }
    }
  );

  fs.readFile("../Template/config.template", "utf8", (err, jsonString) => {
    let config = {};
    if (err) {
      console.log("File read failed:", err);
      return;
    }
    try {
      config = JSON.parse(jsonString);
    } catch (err) {
      console.log("Error parsing JSON string:", err);
    }
    obj = { ...config, ...taskData };
    fs.writeFile(`${path}/config.json`, JSON.stringify(obj), (err) => {
      if (err) {
        console.log("File write failed:", err);
        return;
      }
      res.sendStatus(200);
    });
  });
});

app.listen(PORT, (err) => {
  if (err) {
    console.error(err);
    process.exit(1);
  }
  console.log(`Listening on PORT ${PORT}`);
});
