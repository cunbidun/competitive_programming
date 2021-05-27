import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        PrintWriter out = new PrintWriter(outputStream);
        BNekoPerformsCatFurrierTransform solver = new BNekoPerformsCatFurrierTransform();
        solver.solve(1, in, out);
        out.close();
    }

    static class BNekoPerformsCatFurrierTransform {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            StringBuilder cur = new StringBuilder(Integer.toString(in.nextInt(), 2));
            ArrayList<Integer> ans = new ArrayList<>();
            int cnt = 0;
            while (true) {
                boolean d = true;
                for (int i = 0; i < cur.length(); i++) {
                    if (cur.charAt(i) == '0') {
                        d = false;
                        break;
                    }
                }
                if (d) break;
                cnt++;
                d = false;
                for (int i = 0; i < cur.length(); i++) {
                    if (!d & cur.charAt(i) == '0') {

                        ans.add(cur.length() - i);
                        d = true;
                    }
                    if (d) {
                        if (cur.charAt(i) == '1') cur.setCharAt(i, '0');
                        else cur.setCharAt(i, '1');
                    }
                }
                d = true;
                for (int i = 0; i < cur.length(); i++) {
                    if (cur.charAt(i) == '0') {
                        d = false;
                        break;
                    }
                }
                if (d) break;
                int tmp = Integer.parseInt(cur.toString(), 2);
                tmp++;
                cnt++;
                cur = new StringBuilder(Integer.toString(tmp, 2));
            }
            out.println(cnt);
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}