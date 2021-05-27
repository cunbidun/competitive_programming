package Code;

import Lib.Algorithm.MaxMin;
import Lib.DataStructures.Tuple.PairII;
import FastIO.InputReader;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class LiftHopping {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private int[] d;
    private ArrayList<PairII>[] adj;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            while (true) {
                int n = in.nextInt();
                int k = in.nextInt();
                int[] a = in.nextIntArray(n, 1);
                d = new int[(n + 1) * 101];
                adj = new ArrayList[(n + 1) * 105];
                for (int i = 1; i <= (n + 1) * 101; i++) adj[i] = new ArrayList<>();
                for (int i = 1; i <= 100; i++) {
                    if (i == 1) {
                        for (int j = 1; j <= n; j++) {
                            for (int l = 1; l <= n; l++) {
                                if (l != j) {
                                    adj[trans(j, i)].add(new PairII(0, trans(l, i)));
                                }
                            }
                        }
                        continue;
                    }
                    for (int j = 1; j <= n; j++) {
                        for (int l = 1; l <= n; l++)
                            if (l != j) {
                                adj[trans(j, i)].add(new PairII(60, trans(l, i)));
                            }
                    }
                }
                for (int i = 1; i <= n; i++) {
                    String[] tmp = in.nextLine().split(" ");
                    for (int j = 0; j < tmp.length - 1; j++) {
                        int cur = Integer.parseInt(tmp[j]) + 1;
                        int next = Integer.parseInt(tmp[j + 1]) + 1;
                        adj[trans(i, cur)].add(new PairII((next - cur) * a[i], trans(i, next)));
                        adj[trans(i, next)].add(new PairII((next - cur) * a[i], trans(i, cur)));
                    }
                }
                dijkstra(trans(1, 1));
                int ans = INF;
                for (int i = 1; i <= n; i++) {
                    ans = MaxMin.Min(ans, d[trans(i, k + 1)]);
                }
                if (ans != INF) out.println(ans);
                else out.println("IMPOSSIBLE");
            }
        } catch (Exception ignored) {
        }

    }

    private int trans(int i, int j) {
        return (i - 1) * 100 + j;
    }

    private void dijkstra(int start) {
        PriorityQueue<PairII> pq = new PriorityQueue<>();
        Arrays.fill(d, INF);
        d[start] = 0;
        pq.add(new PairII(0, start));
        while (!pq.isEmpty()) {
            int u = pq.peek().second;
            int du = pq.peek().first;
            pq.poll();
            if (du > d[u]) continue;
            for (PairII p : adj[u]) {
                int v = p.second;
                int uv = p.first;
                if (d[v] > du + uv) {
                    d[v] = du + uv;
                    pq.add(new PairII(d[v], v));
                }
            }
        }
    }
}
