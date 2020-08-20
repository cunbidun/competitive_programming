clang-format-9 -i -style="{ColumnLimit: 0, AllowShortBlocksOnASingleLine: false}" "$1"

if [ $(grep -c " sz(" "$1") = 1 ]; then
	sed -i '/#define sz(v)/d' "$1"
fi

if [ $(grep -c " all(" "$1") = 1 ]; then
	sed -i '/#define all(v)/d' "$1"
fi

# if [ $(grep -c " vi " "$1") = 0 ] && [ $(grep -c "^vi " "$1") = 0 ]; then
# 	sed -i '/typedef vector<int> vi/d' "$1"
# fi

# if [ $(grep -c " ll " "$1") = 0 ] && [ $(grep -c "^ll " "$1") = 0 ]; then
# 	sed -i '/typedef long long ll/d' "$1"
# fi

# if [ $(grep -c " vii " "$1") = 0 ] && [ $(grep -c "^vii " "$1") = 0 ]; then
# 	sed -i '/typedef vector<ii> vii/d' "$1"
# fi

# if [ $(grep -c " ii " "$1") = 0 ] && [ $(grep -c "^ii " "$1") = 0 ]; then
# 	sed -i '/typedef pair<int, int> ii/d' "$1"
# fi


clang-format-9 -i -style="{ColumnLimit: 0, AllowShortBlocksOnASingleLine: false}" "$1"
