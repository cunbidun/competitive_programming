import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.util.Map;
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
        CBankHacking solver = new CBankHacking();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBankHacking {
        private static final int INF = (int) 2e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int max = ArrayAlgorithm.getMax(a, 1, n);
            ArrayList<Integer>[] tree = in.nextTree(n);
            Counter<Integer> counter = new Counter<>();
            for (int i = 1; i <= n; i++) if (a[i] > max - 2) counter.increase(a[i]);
            int ans = INF;
            for (int i = 1; i <= n; i++) {
                int res = a[i];
                if (a[i] > max - 2) counter.decrease(a[i]);
                for (int j : tree[i]) {
                    res = MaxMin.Max(res, a[j] + 1);
                    if (a[j] > max - 2) counter.decrease(a[j]);
                }
                if (!counter.isEmpty())
                    res = MaxMin.Max(counter.lastKey() + 2, res);
                ans = MaxMin.Min(res, ans);
                for (int j : tree[i]) if (a[j] > max - 2) counter.increase(a[j]);
                if (a[i] > max - 2) counter.increase(a[i]);
            }
            out.println(ans);
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class Counter<T extends Comparable<T>> {
        private TreeMap<T, Integer> map = new TreeMap<>();

        public Counter() {
        }

        public void increase(T key) {
            map.merge(key, 1, Integer::sum);
        }

        public void decrease(T key) {
            map.merge(key, -1, Integer::sum);
            if (map.get(key) == 0) map.remove(key);
        }

        public boolean isEmpty() {
            return map.isEmpty();
        }

        public T lastKey() {
            return map.lastKey();
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        public ArrayList<Integer>[] nextTree(int n) {
            ArrayList<Integer>[] tree = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) {
                tree[i] = new ArrayList<>();
            }
            for (int i = 1; i < n; i++) {
                int u = nextInt();
                int v = nextInt();
                tree[u].add(v);
                tree[v].add(u);
            }
            return tree;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class ArrayAlgorithm {
        public static int getMax(int[] array, int stIndex, int enIndex) {
            int max = array[stIndex];
            for (int i = stIndex; i <= enIndex; i++) {
                max = MaxMin.Max(max, array[i]);
            }
            return max;
        }

    }
}