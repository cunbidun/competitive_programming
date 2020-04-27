const app = require('express')();
const bodyParser = require('body-parser');
var mkdirp = require('mkdirp');
const fs = require('fs');
const port = 8080;

app.use(bodyParser.json());

app.post('/', (req, res) => {
    const data = req.body;
    console.log(req.body);
    const path = `../Task/${data.name.replace(/"/g, `'`)}`;
    if (fs.existsSync(path)) {
        res.sendStatus(200);
        return;
    }
    mkdirp(path, function (err) { });
    let tests = [];

    for (let i = 0; i < data.tests.length; i++) {
        let test = {
            "input": data.tests[i].input,
            "output": data.tests[i].output,
            "index": i,
            "active": true,
        };
        tests.push(test);
    }
    fs.copyFile(`../Template/solution.template`, `../Task/${data.name.replace(/"/g, `'`)}/solution.cpp`, function (err) { });
    obj = {
        "tests": tests,
        "name": data.name.replace(/"/g, `'`),
        "group": data.group.replace(/"/g, `'`),
        "isInteractive": data.interactive,
        // "timeLimit": 20000, 
        "timeLimit": data.timeLimit,
        "truncateLongTest": false,
        "checkerParameters": "",
        "useGeneration": false,
        "printWrongAnswer": false,
        "useLocalChecker": false,
        "url": data.url,
        "numTest": 0,
        "genParameters": null,
        "knowGenAns": false,
    };
    fs.writeFile(`../Task/${data.name.replace(/"/g, `'`)}/config.json`, JSON.stringify(obj), function (err) { });
    res.sendStatus(200);
});

app.listen(port, err => {
    if (err) {
        console.error(err);
        process.exit(1);
    }

    console.log(`Listening on port ${port}`);
});
