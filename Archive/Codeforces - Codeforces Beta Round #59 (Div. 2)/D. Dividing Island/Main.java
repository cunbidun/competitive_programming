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
        DDividingIsland solver = new DDividingIsland();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDividingIsland {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            out.println("YES");
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            int d = in.nextInt();
            int n = in.nextInt();
            int[] arr = in.nextIntArray(n, 1);
            char[][] map = new char[110][110];
            boolean B = b >= d;
            if (d > b) {
                int tmp = a;
                a = c;
                c = tmp;
                tmp = b;
                b = d;
                d = tmp;
            }
            for (int j = d + 1; j <= b; j++) {
                for (int i = a + 1; i <= a + c; i++) {
                    map[j][i] = '.';
                }
            }
            int diff = Math.abs(d - b);
            int cur = 1;
            if (diff % 2 == 0) {
                int i = b;
                while (i > d) {
                    for (int j = 1; j <= a; j++) {
                        if (arr[cur] == 0) cur++;
                        map[i][j] = (char) ('a' + cur - 1);
                        arr[cur]--;
                    }
                    i--;
                    if (i <= d) break;
                    for (int j = a; j >= 1; j--) {
                        if (arr[cur] == 0) cur++;
                        map[i][j] = (char) ('a' + cur - 1);
                        arr[cur]--;
                    }
                    i--;
                }
            } else {
                int i = b;
                while (i > d) {
                    for (int j = a; j >= 1; j--) {
                        if (arr[cur] == 0) cur++;
                        map[i][j] = (char) ('a' + cur - 1);
                        arr[cur]--;
                    }

                    i--;
                    if (i <= d) break;
                    for (int j = 1; j <= a; j++) {
                        if (arr[cur] == 0) cur++;
                        map[i][j] = (char) ('a' + cur - 1);
                        arr[cur]--;
                    }
                    i--;
                }
            }

            int i = d;
            while (i > 0) {
                for (int j = 1; j <= a + c; j++) {
                    if (arr[cur] == 0) cur++;
                    map[i][j] = (char) ('a' + cur - 1);
                    arr[cur]--;
                }
                i--;
                if (i <= 0) break;
                for (int j = a + c; j >= 1; j--) {
                    if (arr[cur] == 0) cur++;
                    map[i][j] = (char) ('a' + cur - 1);
                    arr[cur]--;
                }
                i--;

            }

            if (B) {
                for (i = 1; i <= b; i++) {
                    for (int j = 1; j <= a + c; j++) {
                        out.print(map[i][j]);
                    }
                    out.println();
                }
            } else {
                for (i = 1; i <= b; i++) {
                    for (int j = a + c; j >= 1; j--) {
                        out.print(map[i][j]);
                    }
                    out.println();
                }
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