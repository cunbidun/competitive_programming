package Code;

import java.util.ArrayList;
import java.util.Arrays;

@SuppressWarnings("unused")
public class MessageMess {
    private ArrayList<Integer>[] graph;
    private int n, cnt = 0;
    private int[] p;
    private int[] state;

    public String restore(String[] dictionary, String message) {
        n = message.length();
        p = new int[n + 1];
        graph = new ArrayList[n + 1];
        state = new int[n + 1];
        Arrays.fill(state, 0);
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (String s : dictionary) {
            for (int i = 0; i + s.length() <= n; i++) {
                if (message.substring(i, i + s.length()).equals(s)) {
                    graph[i].add(i + s.length());
                }
            }
        }
        dfs(0);
        if (cnt == 0) return "IMPOSSIBLE!";
        if (cnt > 1) return "AMBIGUOUS!";
        StringBuilder ans = new StringBuilder();
        while (n != 0) {
            ans.insert(0, message.substring(p[n], n));
            if (p[n] != 0) ans.insert(0, " ");
            n = p[n];
        }
        return ans.toString();
    }

    private void dfs(int u) {
        for (int v : graph[u]) {
            if (state[v] == 1) continue;
            if (state[v] == 2) {
                cnt = 2;
                return;
            }
            state[v] = 1;
            p[v] = u;
            if (v == n) {
                cnt++;
                state[v] = 2;
            } else dfs(v);
            if (state[v] == 2) state[u] = 2;
        }
    }
}
