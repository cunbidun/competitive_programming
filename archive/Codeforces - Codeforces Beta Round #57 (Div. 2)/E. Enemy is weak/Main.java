import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.io.IOException;
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
        EEnemyIsWeak solver = new EEnemyIsWeak();
        solver.solve(1, in, out);
        out.close();
    }

    static class EEnemyIsWeak {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtil printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtil(out);
            int n = in.nextInt();
            int[] a = ArrayUtil.compress(in.nextIntArray(n, 1), 1, n, 1, true);
            STRangeAddSum biger = new STRangeAddSum(1000000);
            STRangeAddSum smaller = new STRangeAddSum(1000000);
            long ans = 0;
            for (int i = 2; i <= n; i++) {
                if (a[i] != 1000000) smaller.update(a[i] + 1, 1000000, 1);
            }
            for (int i = 1; i < n; i++) {
                ans += (long) biger.getSum(a[i], a[i]) * smaller.getSum(a[i], a[i]);
                if (a[i] != 1) biger.update(1, a[i] - 1, 1);
                if (a[i + 1] != 1000000) smaller.update(a[i + 1] + 1, 1000000, -1);
            }
            out.println(ans);
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class PrinterUtil {
        private PrintWriter out;

        public PrinterUtil(PrintWriter out) {
            this.out = out;
        }

    }

    static class ArrayUtil {
        public static int[] compress(int[] array, int stIndex, int enIndex, int compressValStartAt, boolean order) {
            if (!order) {
                int cnt = compressValStartAt - 1;
                TreeMap<Integer, Integer> map = new TreeMap<>();
                for (int i = stIndex; i <= enIndex; i++) {
                    if (map.get(array[i]) != null) {
                        array[i] = map.get(array[i]);
                    } else {
                        cnt++;
                        map.put(array[i], cnt);
                        array[i] = cnt;
                    }
                }
            } else {
                PairII[] tmp = new PairII[array.length];
                for (int i = stIndex; i <= enIndex; i++) {
                    tmp[i] = new PairII(array[i], i);
                }
                Arrays.sort(tmp, stIndex, enIndex + 1);
                for (int i = stIndex; i <= enIndex; i++) {
                    array[tmp[i].second] = i - stIndex + compressValStartAt;
                }
            }
            return array;
        }

    }

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

    }

    static class STRangeAddSum {
        private int[] segment;
        private int[] lazy;
        private int[] array;
        private int N;

        public STRangeAddSum(int n) {
            segment = new int[4 * n];
            lazy = new int[4 * n];
            N = n;
        }

        public STRangeAddSum(int n, int[] inputArray) {
            segment = new int[4 * n];
            lazy = new int[4 * n];
            this.array = inputArray;
            N = n;
            buildTree(1, 1, N);
        }

        public STRangeAddSum(int n, int[] inputArray, int MOD) {
            segment = new int[4 * n];
            lazy = new int[4 * n];
            this.array = inputArray;
            N = n;
            buildTree(1, 1, N, MOD);
        }

        private void buildTree(int i, int l, int r) {
            if (l > r) return;
            if (l == r) {
                segment[i] = array[l];
                return;
            }
            int m = (l + r) >> 1;
            buildTree(i * 2, l, m);
            buildTree(i * 2 + 1, m + 1, r);
            segment[i] = segment[i * 2] + segment[i * 2 + 1];
        }

        private void buildTree(int i, int l, int r, int MOD) {
            if (l > r) return;
            if (l == r) {
                segment[i] = array[l] % MOD;
                return;
            }
            int m = (l + r) >> 1;
            buildTree(i * 2, l, m, MOD);
            buildTree(i * 2 + 1, m + 1, r, MOD);
            segment[i] = Op.addMod(segment[i * 2], segment[i * 2 + 1], MOD);
        }

        private void trueVal(int i, int l, int r) {
            if (lazy[i] == 0) return;
            segment[i] += lazy[i] * (r - l + 1);
            if (l != r) {
                lazy[i * 2] += lazy[i];
                lazy[i * 2 + 1] += lazy[i];
            }
            lazy[i] = 0;
        }

        private void update(int i, int l, int r, int L, int R, int val) {
            trueVal(i, l, r);
            if (l > r || l > R || r < L) return;
            if (l >= L && r <= R) {
                segment[i] += val * (r - l + 1);
                if (l != r) {
                    lazy[i * 2] += val;
                    lazy[i * 2 + 1] += val;
                }
                return;
            }
            int m = (l + r) >> 1;
            update(i * 2, l, m, L, R, val);
            update(i * 2 + 1, m + 1, r, L, R, val);
            segment[i] = segment[i * 2] + segment[i * 2 + 1];
        }

        private int getSum(int i, int l, int r, int L, int R) {
            trueVal(i, l, r);
            if (l > r || l > R || r < L) return 0;
            if (l >= L && r <= R) return segment[i];
            int m = (l + r) >> 1;
            return getSum(i * 2, l, m, L, R) + getSum(i * 2 + 1, m + 1, r, L, R);
        }

        public void update(int l, int r, int val) {
            update(1, 1, N, l, r, val);
        }

        public int getSum(int l, int r) {
            return getSum(1, 1, N, l, r);
        }

    }

    static class PairII implements Comparable<PairII> {
        public int first;
        public int second;

        public PairII(int first, int second) {
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

            PairII pair = (PairII) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }
}