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
        BPlusFromPicture solver = new BPlusFromPicture();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPlusFromPicture {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            char[][] a = in.nextCharTable(n, m, 1, 1);
            boolean[][] ch = new boolean[n + 1][m + 1];
            int posi = -1;
            int posj = -1;
            for (int i = 2; i < n; i++) {
                for (int j = 2; j < m; j++) {
                    if (a[i][j] == '*' && a[i - 1][j] == '*' && a[i + 1][j] == '*' && a[i][j - 1] == '*' && a[i][j + 1] == '*') {
                        posi = i;
                        posj = j;
                    }
                }
            }
            if (posi == -1) {
                out.println("NO");
                return;
            }
            for (int i = posi; i <= n; i++) {
                if (a[i][posj] == '*') {
                    ch[i][posj] = true;
                } else break;

            }
            for (int i = posi; i >= 1; i--) {
                if (a[i][posj] == '*') {
                    ch[i][posj] = true;
                } else break;

            }
            for (int j = posj; j <= m; j++) {
                if (a[posi][j] == '*') {
                    ch[posi][j] = true;
                } else break;

            }
            for (int j = posj; j >= 1; j--) {
                if (a[posi][j] == '*') {
                    ch[posi][j] = true;
                } else break;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] == '*' && !ch[i][j]) {
                        out.println("NO");
                        return;
                    }
                }
            }
            out.println("YES");
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
}