package Code;

import Lib.DataStructures.Tuple.PairII;
import Lib.DataStructures.Tuple.PairLI;
import FastIO.InputReader;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class SendingEmail {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private int n;
    private long[] d;
    private ArrayList<PairII>[] adj;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int cnt = 0;
        int t = in.nextInt();
        while (t-- > 0) {
            cnt++;
            n = in.nextInt();
            d = new long[n + 1];
            adj = new ArrayList[n + 1];
            int m = in.nextInt();
            int S = in.nextInt() + 1;
            int T = in.nextInt() + 1;
            for (int i = 1; i <= n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int w = in.nextInt();
                u++;
                v++;
                adj[u].add(new PairII(w, v));
                adj[v].add(new PairII(w, u));
            }
            dijkstra(S);
            out.print("Case #" + cnt + ": ");
            if (d[T] == INF) out.println("unreachable");
            else out.println(d[T]);
        }
    }

    private void dijkstra(int start) {
        PriorityQueue<PairLI> pq = new PriorityQueue<>();
        for (int i = 1; i <= n; i++) d[i] = INF;
        d[start] = 0;
        pq.add(new PairLI(0, start));
        while (!pq.isEmpty()) {
            int u = pq.peek().second;
            long du = pq.peek().first;
            pq.poll();
            if (du > d[u]) continue;
            for (PairII p : adj[u]) {
                int v = p.second;
                long uv = p.first;
                if (d[v] > du + uv) {
                    d[v] = du + uv;
                    pq.add(new PairLI(d[v], v));
                }
            }
        }
    }
}
