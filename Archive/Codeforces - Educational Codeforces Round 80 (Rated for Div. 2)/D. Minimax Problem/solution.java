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
        Task1288D solver = new Task1288D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1288D {
        private InputReader in;
        private OutputWriter out;
        int[][] a;
        int n;
        int m;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            m = in.nextInt();
            a = in.nextIntTable(n, m, 1, 1);
            int l = 0, r = (int) 1e9;
            while (l != r) {
                if (l + 1 == r) {
                    if (ch(r)) l = r;
                    break;
                }
                int mid = (l + r) >> 1;
                if (ch(mid)) l = mid;
                else r = mid - 1;
            }

            int[] ch = new int[500];
            int[] arr = new int[n + 1];

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] >= l) {
                        arr[i] += (1 << (j - 1));
                    }
                }
                ch[arr[i]] = i;

            }
            ArrayList<Integer> list = new ArrayList<>();
            for (int i = 0; i < (1 << m); i++) {
                if (ch[i] != 0) {
                    list.add(i);
                }
            }
            for (int i = 0; i < list.size(); i++) {
                for (int j = 0; j < list.size(); j++) {
                    if ((list.get(i) | list.get(j)) == ((1 << m) - 1)) {
                        out.println(ch[list.get(i)] + " " + ch[list.get(j)]);
                        return;
                    }
                }
            }
        }

        private boolean ch(int x) {
            int[] arr = new int[n + 1];

            int[] ch = new int[500];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] >= x) {
                        arr[i] += (1 << (j - 1));
                    }
                }
                ch[arr[i]] = i;
            }
            ArrayList<Integer> list = new ArrayList<>();
            for (int i = 0; i < (1 << m); i++) {
                if (ch[i] != 0) {
                    list.add(i);
                }
            }
            for (int i = 0; i < list.size(); i++) {
                for (int j = 0; j < list.size(); j++) {
                    if ((list.get(i) | list.get(j)) == ((1 << m) - 1))
                        return true;
                }
            }
            return false;
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

        public int[][] nextIntTable(int row, int col, int rowSt, int colSt) {
            int[][] arr = new int[row + rowSt][col + colSt];
            for (int i = rowSt; i < row + rowSt; i++) {
                for (int j = colSt; j < col + colSt; j++) {
                    arr[i][j] = nextInt();
                }
            }
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

        public void println(String i) {
            out.println(i);
        }

    }
}