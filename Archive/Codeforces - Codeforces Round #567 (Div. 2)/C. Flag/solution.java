import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        CFlag solver = new CFlag();
        solver.solve(1, in, out);
        out.close();
    }

    static class CFlag {
        private InputReader in;
        private PrintWriter out;
        private char[][] a;
        private int[][][] sum;
        private int n;
        private int m;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            m = in.nextInt();
            a = in.nextCharTable(n, m, 1, 1);
            sum = new int[n + 1][m + 1][55];

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        sum[i][j][index(c)] = sum[i - 1][j][index(c)] + sum[i][j - 1][index(c)] - sum[i - 1][j - 1][index(c)];
                    }
                    for (char c = 'A'; c <= 'Z'; c++) {
                        sum[i][j][index(c)] = sum[i - 1][j][index(c)] + sum[i][j - 1][index(c)] - sum[i - 1][j - 1][index(c)];
                    }
                    sum[i][j][index(a[i][j])]++;
                }
            }
//
            long ans = 0;
            boolean[][] done = new boolean[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] != a[i - 1][j] && !done[i][j]) {
                        int low = i;
                        int high = n;

                        while (low != high) {
                            if (low == high - 1) {
                                if (check(i, j, high, j)) low = high;
                                break;
                            }
                            int mid = (low + high) >> 1;
                            if (check(i, j, mid, j)) low = mid;
                            else high = mid - 1;
                        }
                        int pos = low;
                        int dis = low - i + 1;

                        if (pos + dis > n || i - dis < 1) continue;
                        if (!check(i - dis, j, i - 1, j) || !check(pos + 1, j, pos + dis, j)) continue;
                        low = j;
                        high = m;
                        while (low != high) {
                            if (low == high - 1) {
                                if (check(i, j, pos, high)) low = high;
                                break;
                            }
                            int mid = (low + high) >> 1;
                            if (check(i, j, pos, mid)) low = mid;
                            else high = mid - 1;
                        }
                        int cnt2 = low - j + 1;

                        low = j;
                        high = m;
                        while (low != high) {
                            if (low == high - 1) {
                                if (check(i - dis, j, i - 1, high)) low = high;
                                break;
                            }
                            int mid = (low + high) >> 1;
                            if (check(i - dis, j, i - 1, mid)) low = mid;
                            else high = mid - 1;
                        }
                        int cnt1 = low - j + 1;

                        low = j;
                        high = m;
                        while (low != high) {
                            if (low == high - 1) {
                                if (check(pos + 1, j, pos + dis, high)) low = high;
                                break;
                            }
                            int mid = (low + high) >> 1;
                            if (check(pos + 1, j, pos + dis, mid)) low = mid;
                            else high = mid - 1;
                        }
                        int cnt3 = low - j + 1;

                        int cur = MaxMin.Min(cnt1, cnt2, cnt3);

                        for (int l = j; l <= j + cur - 1; l++) {
                            done[i][l] = true;
                        }
                        ans += cur * (cur - 1) / 2 + cur;
                    }
                }
            }

            out.println(ans);
        }

        private boolean check(int i, int j, int k, int l) {
            int tmp = (k - i + 1) * (l - j + 1);
            char c = a[i][j];
            return getSum(i, j, k, l, index(c)) == tmp;
        }

        private int getSum(int i, int j, int k, int l, int index) {
            return sum[k][l][index] - sum[k][j - 1][index] - sum[i - 1][l][index] + sum[i - 1][j - 1][index];
        }

        private int index(char c) {
            if (c <= 'Z') return c - 'A' + 1;
            else return c - 'a' + 1 + 26;
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

        public char[][] nextCharTable(int row, int col, int rowSt, int colSt) {
            char[][] arr = new char[row + rowSt][col + colSt];
            for (int i = rowSt; i < row + rowSt; i++) {
                for (int j = colSt; j < col + colSt; j++) {
                    arr[i][j] = nextCharacter();
                }
            }
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y, T z) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            if (z.compareTo(min) < 0) min = z;
            return min;
        }

    }
}