import re
from pathlib import Path

import toml

if __name__ == "__main__":
    data = {}
    with open("Cargo.toml", "r", encoding="utf-8") as f:
        data = toml.load(f)
        data["bin"] = []
        paths = list(Path("./task").rglob("*.rs")) + list(Path("./archive").rglob("*.rs"))
        for path in paths:
            data["bin"].append({"name": re.sub(r"\W+", "_", str(path).lower()), "path": str(path)})

    with open("Cargo.toml", "w", encoding="utf-8") as f:
        print(toml.dump(data, f))
