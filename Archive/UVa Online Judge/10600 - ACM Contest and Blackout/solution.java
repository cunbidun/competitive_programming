package Code;

import Lib.Algorithm.MaxMin;
import Lib.Algorithm.TreeAlgorithm.LCA.LCAMax;
import Lib.DataStructures.Tree.TreeList.TreeList;
import Lib.DataStructures.Tuple.PairII;
import Lib.DataStructures.Tuple.TripIII;
import Lib.DataStructures.UnionFind;
import FastIO.InputReader;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

public class ACMContestAndBlackout {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            int m = in.nextInt();
            ArrayList<PairII>[] tree = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) tree[i] = new ArrayList<>();
            TreeList<TripIII> edgeList = new TreeList<>();
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int w = in.nextInt();
                edgeList.add(new TripIII(w, u, v));
            }
            Collections.sort(edgeList);
            int MST = 0;
            UnionFind dsu = new UnionFind(n);
            for (int i = 0; i < edgeList.size(); i++) {
                TripIII T = edgeList.get(i);
                int w = T.first;
                int u = T.second;
                int v = T.third;
                if (!dsu.isSameSet(u, v)) {
                    MST += w;
                    dsu.mergeSet(u, v);
                    tree[u].add(new PairII(v, w));
                    tree[v].add(new PairII(u, w));
                    edgeList.remove(T);
                    i--;
                }
            }
            out.print(MST + " ");
            int secondMin = INF;
            LCAMax LCA = new LCAMax(tree, n, 1);
            for (TripIII T: edgeList) {
                int u = T.second;
                int v = T.third;
                secondMin = MaxMin.Min(secondMin, MST + T.first - LCA.getMaxBetween(u,v));
            }
            out.println(secondMin);
        }
    }
}
