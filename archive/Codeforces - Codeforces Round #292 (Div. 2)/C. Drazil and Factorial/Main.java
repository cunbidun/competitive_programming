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
        CDrazilAndFactorial solver = new CDrazilAndFactorial();
        solver.solve(1, in, out);
        out.close();
    }

    static class CDrazilAndFactorial {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            ArrayList<Integer> numList = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                char c = in.nextCharacter();
                int cur = c - '0';
                if (cur == 1 || cur == 0) continue;
                else if (cur == 4) {
                    numList.add(2);
                    numList.add(2);
                    numList.add(3);
                } else if (cur == 6) {
                    numList.add(5);
                    numList.add(3);
                } else if (cur == 8) {
                    numList.add(2);
                    numList.add(2);
                    numList.add(2);
                    numList.add(7);
                } else if (cur == 9) {
                    numList.add(3);
                    numList.add(3);
                    numList.add(2);
                    numList.add(7);
                } else numList.add(cur);
            }
            numList.sort(Collections.reverseOrder());
            for (int i : numList) out.print(i);
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

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

    }
}