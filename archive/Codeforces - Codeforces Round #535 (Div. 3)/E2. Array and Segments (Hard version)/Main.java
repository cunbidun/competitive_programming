import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        E2ArrayAndSegmentsHardVersion solver = new E2ArrayAndSegmentsHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E2ArrayAndSegmentsHardVersion {
        static final int MAXA = (int) 1e5 + 10;
        static final int INF = (int) 2e9 + 7;
        int[] a = new int[MAXA];
        int[] segmentTree = new int[MAXA * 4];
        int[] lazy = new int[MAXA * 4];
        PairIntInt[] seg = new PairIntInt[MAXA];
        ArrayList<Integer>[] end = new ArrayList[MAXA];
        ArrayList<Integer>[] start = new ArrayList[MAXA];
        ArrayList<Integer> res = new ArrayList<>();
        int ans = 0;

        private void trueVal(int id, int l, int r) {
            if (lazy[id] == 0 || l > r) return;
            segmentTree[id] += lazy[id];
            if (l != r) {
                lazy[id * 2] += lazy[id];
                lazy[id * 2 + 1] += lazy[id];
            }
            lazy[id] = 0;
        }

        private void buildTree(int id, int l, int r) {
            if (l > r) return;
            if (l == r) {
                segmentTree[id] = a[l];
                return;
            }
            int m = (l + r) >> 1;
            buildTree(id * 2, l, m);
            buildTree(id * 2 + 1, m + 1, r);
            segmentTree[id] = Math.min(segmentTree[id * 2], segmentTree[id * 2 + 1]);
        }

        private void update(int id, int l, int r, int tarL, int tarR) {
            trueVal(id, l, r);
            if (l > tarR || r < tarL || l > r) return;
            int m = (l + r) >> 1;
            if (tarL <= l && r <= tarR) {
                segmentTree[id] += -1;
                if (l != r) {
                    lazy[id * 2] += -1;
                    lazy[id * 2 + 1] += -1;
                }
                return;
            }
            update(id * 2, l, m, tarL, tarR);
            update(id * 2 + 1, m + 1, r, tarL, tarR);
            segmentTree[id] = Math.min(segmentTree[id * 2], segmentTree[id * 2 + 1]);
        }

        private int getMin(int id, int l, int r, int tarL, int tarR) {
            trueVal(id, l, r);
            if (l > tarR || r < tarL || l > r) return INF;
            if (tarL <= l && r <= tarR) return segmentTree[id];
            int m = (l + r) >> 1;
            return Math.min(getMin(id * 2, l, m, tarL, tarR), getMin(id * 2 + 1, m + 1, r, tarL, tarR));
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            for (int i = 0; i <= n + 1; i++) {
                start[i] = new ArrayList<>();
                end[i] = new ArrayList<>();
            }
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
            }
            for (int i = 1; i <= m; i++) {
                seg[i] = new PairIntInt(in.nextInt(), in.nextInt());
                start[seg[i].first].add(i);
                end[seg[i].second].add(i);
            }
            int posI = 0;
            Arrays.fill(lazy, 0);
            Arrays.fill(segmentTree, INF);
            buildTree(1, 1, n);

//        update(1, 1, n, 1, 3);
//        update(1, 1, n, 1, 4);
//        out.println(getMin(1, 1, n, 2, 2));
//        update(1, 1, n, 2, 4);
//        out.println(getMin(1, 1, n, 1, 4));
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < end[i - 1].size(); j++) {
                    update(1, 1, n, seg[end[i - 1].get(j)].first, seg[end[i - 1].get(j)].second);
                }
//            int tmp = getMin(1, 1, n, 1, i - 1);
//            out.println(i + " " + tmp);
                int tmp = a[i] - getMin(1, 1, n, 1, i - 1);
                if (ans < tmp) {
                    ans = tmp;
                    posI = i;
                }
            }

            Arrays.fill(segmentTree, INF);
            Arrays.fill(lazy, 0);
            buildTree(1, 1, n);
            for (int i = n; i >= 1; i--) {
                for (int j = 0; j < start[i + 1].size(); j++) {
                    //out.println(i + " " + seg[start[i + 1].get(j)].first + " " + seg[start[i + 1].get(j)].second);
                    update(1, 1, n, seg[start[i + 1].get(j)].first, seg[start[i + 1].get(j)].second);
                }
                int tmp = a[i] - getMin(1, 1, n, i + 1, n);
                //out.println(i + " " + tmp);
                if (ans < tmp) {
                    ans = tmp;
                    posI = i;
                }
            }
            out.println(ans);
            for (int i = 1; i <= m; i++) {
                if (posI > seg[i].second || posI < seg[i].first) res.add(i);
            }
            out.println(res.size());
            for (int i = 0; i < res.size(); i++) {
                out.print(res.get(i) + " ");
            }
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class PairIntInt implements Comparable<PairIntInt> {
        public int first;
        public int second;

        public PairIntInt(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            PairIntInt pair = (PairIntInt) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairIntInt o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }
}