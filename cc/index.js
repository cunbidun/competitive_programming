import express from "express";
import { copyFile, readFile, writeFile } from "fs";
import path from "path";
import mkdirp from "mkdirp";
import dotenv from "dotenv";
dotenv.config({
  path: path.join(path.resolve(process.env.CPS_PATH), "project_config"),
});

const app = express();
app.use(express.json());

const PORT = 8080;

function reformat(s) {
  return s.replace(/"/g, `'`).replace(/!/g, ``).replace(/\//g, `-`).replace(/'/g, ``).replace(/#/g, ``);
}

app.post("/", async (req, res) => {
  console.log(req.body);
  const data = req.body;
  data.name = reformat(data.name);
  data.group = reformat(data.group);

  const root_path = path.join(path.resolve(process.env.TASK_PATH), data.name);
  const root_solution_path = path.join(
    path.resolve(root_path),
    "solution.cpp"
  );
  const root_config_path = path.join(
    path.resolve(root_path),
    "config.json"
  );
  const template_solution_path = path.join(
    path.resolve(process.env.TEMPLATE_PATH),
    "solution.template"
  );
  const template_config_path = path.join(
    path.resolve(process.env.TEMPLATE_PATH),
    "config.template"
  );

  await mkdirp(root_path, (err) => {
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

  let taskData = {
    tests: tests,
    name: data.name,
    group: data.group,
    timeLimit: data.timeLimit !== null ? data.timeLimit : 5000,
    url: data.url,
  };

  copyFile(template_solution_path, root_solution_path, (err) => {
    if (err) {
      console.log("File copy failed:", err);
      return;
    }
  });

  readFile(template_config_path, "utf8", (err, jsonString) => {
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
    let obj = { ...config, ...taskData };
    writeFile(root_config_path, JSON.stringify(obj), (err) => {
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
