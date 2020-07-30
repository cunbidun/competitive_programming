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
        CServalAndParenthesisSequence solver = new CServalAndParenthesisSequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class CServalAndParenthesisSequence {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            if (n % 2 == 1) {
                out.println(":(");
                return;
            }
            char[] a = in.nextCharArray(n, 1);
            if (a[1] == ')' || a[n] == '(') {
                out.println(":(");
                return;
            }
            a[1] = '(';
            a[n] = ')';
            int cnt = 0;
            int open = 0;
            int close = 0;
            for (int i = 2; i <= n - 1; i++) {
                if (a[i] == '(') {
                    open++;
                } else if (a[i] == ')') {
                    close++;
                }

            }
            if (open > (n - 2) / 2 || close > (n - 2) / 2) {
                out.println(":(");
                return;
            }
            open = (n - 2) / 2 - open;
            for (int i = 2; i <= n - 1; i++) {
                if (a[i] == '(') {
                    cnt++;
                } else if (a[i] == ')') {
                    cnt--;
                } else {
                    if (open > 0) {
                        a[i] = '(';
                        open--;
                        cnt++;
                    } else {
                        a[i] = ')';
                        cnt--;
                    }
                }
                if (cnt < 0) {
                    out.println(":(");
                    return;
                }
            }
            if (cnt != 0) {
                out.println(":(");
                return;
            }
            for (int i = 1; i <= n; i++) {
                out.print(a[i]);
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

        public char[] nextCharArray(int length, int stIndex) {
            char[] arr = new char[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextCharacter();
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