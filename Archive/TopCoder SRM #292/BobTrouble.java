package Code;

import Lib.DataStructures.UnionFind;

import java.util.TreeMap;
import java.util.TreeSet;

@SuppressWarnings("unused")
public class BobTrouble {
    public int minSupers(String[] name, String[] bossName) {
        UnionFind dsu = new UnionFind(name.length);
        TreeMap<String, Integer> map = new TreeMap<>();
        int pos = 0;
        for (String i : name) {
            if (!i.equals("BOB")) {
                map.put(i, pos);
            }
            pos++;
        }
        boolean f = true;
        boolean check = false;
        TreeSet<String> set = new TreeSet<>();
        for (int i = 0; i < name.length; i++) {
            if (!bossName[i].equals("BOB") && !bossName[i].equals("*")) set.add(bossName[i]);
            if (bossName[i].equals("BOB")) check = true;
        }
        int cnt = set.size();

        for (int i = 0; i < name.length; i++) {
            if (!bossName[i].equals("BOB") && !name[i].equals("BOB") && !bossName[i].equals("*")) {
                if (dsu.isSameSet(i, map.get(bossName[i]))) {
                    return -1;
                }
                dsu.merge(i, map.get(bossName[i]));
            }
        }
        if (!check) return cnt;
        for (int i = 0; i < name.length; i++)
            if (name[i].equals("BOB") && !bossName[i].equals("BOB")) {
                if (bossName[i].equals("*")) return cnt + 1;
                int cur = map.get(bossName[i]);
                while (true) {
                    if (bossName[cur].equals("*")) return cnt + 1;
                    if (bossName[cur].equals("BOB")) break;
                    cur = map.get(bossName[cur]);
                }
            }
        return -1;
    }
}