import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        OutputWriter out = new OutputWriter(outputStream);
        Task746G solver = new Task746G();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task746G {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int t = in.nextInt();
            int k = in.nextInt();
            int[] a = in.nextIntArray(t, 1);

            ArrayList<Integer>[] tree = new ArrayList[n + 1];
            ArrayList<Integer>[] ans = new ArrayList[n + 1];
            ArrayList<Integer> first = new ArrayList<>();
            boolean[] change = new boolean[n + 1];
            for (int i = 1; i <= n; i++) {
                ans[i] = new ArrayList<>();
                tree[i] = new ArrayList<>();
            }
            int last = 1;
            int cur = 2;
            first.add(1);
            for (int i = 1; i <= t; i++) {
                while (a[i] != 0) {
                    tree[last].add(cur);
                    cur++;
                    a[i]--;
                }
                last = tree[last].get(0);
                first.add(last);
            }
            int nL = n - t;
            if (nL < k) {
                out.println(-1);
                return;
            }
            for (int i = 1; i < first.size(); i++) {
                cur = first.get(i);
                last = first.get(i - 1);
                int size = MaxMin.Min(tree[cur].size(), tree[last].size());
                for (int j = 1; j < size; j++) {
                    if (nL == k) break;
                    int tmp1 = tree[last].get(tree[last].size() - j);
                    int tmp2 = tree[cur].get(tree[cur].size() - j);
                    ans[tmp1].add(tmp2);
                    change[tmp2] = true;
                    nL--;
                }
                if (nL == k) break;
            }
            if (nL != k) {
                out.println(-1);
                return;
            }
            out.println(n);
            for (int i = 1; i <= n; i++) {
                for (int j : ans[i]) out.println(i + " " + j);
            }
            for (int i = 1; i <= n; i++) {
                for (int j : tree[i]) if (!change[j]) out.println(i + " " + j);
            }
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

        public void println(String i) {
            out.println(i);
        }

    }
}