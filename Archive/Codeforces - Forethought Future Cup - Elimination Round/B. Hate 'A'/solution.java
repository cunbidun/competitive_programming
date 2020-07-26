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
        BHateA solver = new BHateA();
        solver.solve(1, in, out);
        out.close();
    }

    static class BHateA {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            String s = in.nextString();
            StringBuilder sp = new StringBuilder();

            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) != 'a') {
                    sp.append(s.charAt(i));
                }
            }
            if (sp.length() == 0) {
                out.println(s);
                return;
            }
            if (s.charAt(s.length() - 1) == 'a') {
                out.println(":(");
                return;
            }
            if (sp.length() % 2 != 0 || !sp.substring(0, sp.length() / 2).equals(sp.substring(sp.length() / 2)) || !s.endsWith(sp.toString().substring(sp.length() / 2))) {
                out.println(":(");
                return;
            }
            for (int i = 0; i < s.length() - sp.length() / 2; i++) out.print(s.charAt(i));
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

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}