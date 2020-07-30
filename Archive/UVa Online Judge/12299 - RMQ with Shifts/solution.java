package Code;

import Lib.DataStructures.Tree.SegmentTree.STPointSetMin;
import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection", "FieldCanBeLocal", "RedundantSuppression"})
public class RMQWithShifts {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private InputReader in;
    private PrintWriter out;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        this.in = in;
        this.out = out;
        int n = in.nextInt();
        int q = in.nextInt();
        int[] a = in.nextIntArray(n, 1);
        STPointSetMin st = new STPointSetMin(n);
        for (int i = 1; i <= n; i++) {
            st.set(i, a[i]);
        }
        while (q-- > 0) {
            char c = '0';
            for (int i = 1; i <= 5; i++) {
                c = in.nextCharacter();
            }
            String[] s = in.nextString().split(",");
            s[0] = s[0].substring(1);
            s[s.length - 1] = s[s.length - 1].substring(0, s[s.length - 1].length() - 1);
            if (c == 'y') {
                out.println(st.getMin(Integer.parseInt(s[0]), Integer.parseInt(s[1])));
            } else {
//                for (String s1 : s) {
//                    out.print(Integer.parseInt(s1) + " ");
//                }
//                out.println();
                int tmp = a[Integer.parseInt(s[0])];
                for (int i = 0; i < s.length - 1; i++) {
                    st.set(Integer.parseInt(s[i]), a[Integer.parseInt(s[i + 1])]);
                    a[Integer.parseInt(s[i])] = a[Integer.parseInt(s[i + 1])];
                }
                st.set(Integer.parseInt(s[s.length - 1]), tmp);
                a[Integer.parseInt(s[s.length - 1])] = tmp;
            }
        }
    }
}
