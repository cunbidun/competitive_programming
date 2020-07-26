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
        Task1255D solver = new Task1255D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1255D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int t = in.nextInt();
            while (t-- > 0) {
                int r = in.nextInt();
                int c = in.nextInt();
                int k = in.nextInt();
                char[][] a = in.nextCharTable(r, c, 1, 1);

                int cnt = 0;
                for (int i = 1; i <= r; i++) {
                    for (int j = 1; j <= c; j++) {
                        if (a[i][j] == 'R') {
                            cnt++;
                        }
                    }
                }

                int tot = cnt / k;
                int extra = cnt % k;
                int cur = 1;
                int curFood = tot;
                if (extra > 0) {
                    curFood++;
                    extra--;
                }
                for (int i = 1; i <= r; i++) {
                    if (i % 2 == 1) {
                        for (int j = 1; j <= c; j++) {
                            if (cur == k + 1) {
                                a[i][j] = get(k);
                                continue;
                            }
                            if (a[i][j] == 'R') {
                                a[i][j] = get(cur);
                                curFood--;
                                if (curFood == 0) {
                                    cur++;
                                    curFood = tot;
                                    if (extra > 0) {
                                        curFood++;
                                        extra--;
                                    }
                                }
                            } else a[i][j] = get(cur);
                        }
                    }
                    if (i % 2 == 0) {
                        for (int j = c; j >= 1; j--) {
                            if (cur == k + 1) {
                                a[i][j] = get(k);
                                continue;
                            }
                            if (a[i][j] == 'R') {
                                a[i][j] = get(cur);
                                curFood--;
                                if (curFood == 0) {
                                    cur++;
                                    curFood = tot;
                                    if (extra > 0) {
                                        curFood++;
                                        extra--;
                                    }
                                }
                            } else a[i][j] = get(cur);
                        }
                    }
                }
                for (int i = 1; i <= r; i++) {
                    for (int j = 1; j <= c; j++) {
                        out.print(a[i][j]);
                    }
                    out.println("");
                }
            }
        }

        public char get(int k) {
            if (k <= 10) return (char) ('0' + k - 1);
            if (k <= 36) return (char) ('A' + k - 11);
            return (char) ('a' + k - 37);
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

        public void print(char i) {
            out.print(i);
        }

        public void println(String i) {
            out.println(i);
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