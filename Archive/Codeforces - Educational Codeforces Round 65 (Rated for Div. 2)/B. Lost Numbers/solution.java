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
        BLostNumbers solver = new BLostNumbers();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLostNumbers {
        private InputReader in;
        private PrintWriter out;
        private int n = 6;
        private int a;
        private int b;
        private int c;
        private int d;
        private boolean[] used = new boolean[10];
        private int[] arr = new int[10];
        private int[] sample = {0, 4, 8, 15, 16, 23, 42};
        private boolean done = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            a = ask(1, 2);
            b = ask(2, 3);
            c = ask(4, 5);
            d = ask(5, 6);
            backtrack(1);
        }

        private void backtrack(int pos) {
            if (pos == n + 1) {
                if (sample[arr[1]] * sample[arr[2]] == a && sample[arr[2]] * sample[arr[3]] == b && sample[arr[4]] * sample[arr[5]] == c && sample[arr[5]] * sample[arr[6]] == d) {
                    out.println("! " + sample[arr[1]] + " " + sample[arr[2]] + " " + sample[arr[3]] + " " + sample[arr[4]] + " " + sample[arr[5]] + " " + sample[arr[6]]);
                    out.flush();

                    done = true;
                }
                return;
            }
            for (int i = 1; i <= n; i++) {
                if (done) return;
                if (!used[i]) {
                    arr[pos] = i;
                    used[i] = true;
                    backtrack(pos + 1);
                    if (done) return;
                    used[i] = false;
                }
            }
        }

        public int ask(int i, int j) {
            out.println("? " + i + " " + j);
            out.flush();
            return in.nextInt();
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}