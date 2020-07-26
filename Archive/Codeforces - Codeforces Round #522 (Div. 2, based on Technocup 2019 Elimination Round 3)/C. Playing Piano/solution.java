import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Collections;
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
        CPlayingPiano solver = new CPlayingPiano();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPlayingPiano {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            boolean[][] f = new boolean[n + 1][6];
            f[1][1] = true;
            f[1][2] = true;
            f[1][3] = true;
            f[1][4] = true;
            f[1][5] = true;
            for (int i = 2; i <= n; i++) {
                if (a[i] > a[i - 1]) {
                    for (int j = 1; j <= 5; j++)
                        if (f[i - 1][j]) {
                            for (int k = j + 1; k <= 5; k++) {
                                f[i][k] = true;
                            }
                        }
                } else if (a[i] < a[i - 1]) {
                    for (int j = 5; j >= 1; j--) {
                        if (f[i - 1][j]) {
                            for (int k = j - 1; k >= 1; k--) {
                                f[i][k] = true;
                            }
                        }
                    }
                } else {
                    for (int j = 1; j <= 5; j++) {
                        for (int k = 1; k <= 5; k++) {
                            if (f[i - 1][j] && j != k) f[i][k] = true;
                        }
                    }
                }
                boolean fa = true;
                for (int j = 1; j <= 5; j++) {
                    if (f[i][j]) {
                        fa = false;
                        break;
                    }
                }
                if (fa) {
                    out.println(-1);
                    return;
                }
            }

            int pos = 0;
            for (int i = 1; i <= 5; i++) {
                if (f[n][i]) {
                    pos = i;
                    break;
                }
            }

            ArrayList<Integer> ans = new ArrayList<>();
            int last = pos;
            ans.add(pos);
            pos = n;
            while (pos > 0) {
                if (a[pos] > a[pos - 1]) {
                    for (int i = last - 1; i >= 1; i--)
                        if (f[pos - 1][i]) {
                            last = i;
                            ans.add(i);
                            break;
                        }
                } else if (a[pos] < a[pos - 1]) {
                    for (int i = last + 1; i <= 5; i++)
                        if (f[pos - 1][i]) {
                            last = i;
                            ans.add(i);
                            break;
                        }
                } else {
                    for (int i = 1; i <= 5; i++)
                        if (f[pos - 1][i] && i != last) {
                            last = i;
                            ans.add(i);
                            break;
                        }
                }
                pos--;
            }
            Collections.reverse(ans);
            for (int i : ans) {
                out.print(i + " ");
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
}