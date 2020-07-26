import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        OutputWriter out = new OutputWriter(outputStream);
        TheSpyNetwork solver = new TheSpyNetwork();
        solver.solve(1, in, out);
        out.close();
    }

    static class TheSpyNetwork {
        private InputReader in;
        private OutputWriter out;
        private ArrayList<TripIII>[] tree;
        private ArrayList<Integer> ans;
        private int[] lvl;
        private int[] p;
        private int[] mxLength;
        private boolean[] ch;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            ch = new boolean[n + 1];
            lvl = new int[n + 1];
            mxLength = new int[n + 1];
            p = new int[n + 1];
            tree = new ArrayList[n + 1];
            ans = new ArrayList<>();
            for (int i = 1; i <= n; i++) tree[i] = new ArrayList<>();
            for (int i = 1; i < n; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                String tmp = in.nextString();
                if (tmp.charAt(0) == 'p') {
                    tree[u].add(new TripIII(v, i, 1));
                    tree[v].add(new TripIII(u, i, 1));
                    continue;
                }
                tree[u].add(new TripIII(v, i, 0));
                tree[v].add(new TripIII(u, i, 0));
                tmp = in.nextString();
            }
            dfs(1, 1);
            sol(1, 1);
            out.println(ans.size());
            out.println(ans);
        }

        private void sol(int u, int l) {
            for (TripIII p : tree[u]) {
                int v = p.first;
                if (v != l) {
                    sol(v, u);
                    if (!ch[p.second] && mxLength[v] + 1 > lvl[u]) {
                        ans.add(p.second);
                        ch[p.second] = true;
                    }
                    if (ch[p.second])
                        mxLength[u] = MaxMin.Max(mxLength[u], mxLength[v] - 1);
                    else
                        mxLength[u] = MaxMin.Max(mxLength[u], mxLength[v] + 1);
                }
            }
//        System.out.println(u + " " + mxLength[u]);
        }

        private void dfs(int u, int l) {
            for (TripIII v : tree[u]) {
                if (v.first != l) {
                    lvl[v.first] = lvl[u] + 1;
                    p[v.first] = u;
                    if (v.third == 1)
                        ch[v.second] = true;
                    dfs(v.first, u);
                }
            }
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

    }

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void println(int i) {
            out.println(i);
        }

        public void print(ArrayList<Integer> a) {
            for (int i : a) out.print(i + " ");
        }

        public void println(ArrayList<Integer> a) {
            print(a);
            out.println();
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
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

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class TripIII implements Comparable<TripIII> {
        public int first;
        public int second;
        public int third;

        public TripIII(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            TripIII trip = (TripIII) o;

            return first == trip.first && second == trip.second && third == trip.third;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + ")";
        }

        public int compareTo(TripIII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(second, o.second);
            if (value != 0) {
                return value;
            }
            return Integer.compare(third, o.third);
        }

    }
}