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
        AMiddleOfTheContest solver = new AMiddleOfTheContest();
        solver.solve(1, in, out);
        out.close();
    }

    static class AMiddleOfTheContest {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String t1 = in.nextString();
            String t2 = in.nextString();
            String h1 = t1.substring(0, 2);
            String m1 = t1.substring(3, 5);
            int x1 = (h1.charAt(0) - '0') * 10 + (h1.charAt(1) - '0');
            int y1 = (m1.charAt(0) - '0') * 10 + (m1.charAt(1) - '0');

            String h2 = t2.substring(0, 2);
            String m2 = t2.substring(3, 5);
            int x2 = (h2.charAt(0) - '0') * 10 + h2.charAt(1) - '0';
            int y2 = (m2.charAt(0) - '0') * 10 + m2.charAt(1) - '0';

            int num1 = x1 * 60 + y1;
            int num2 = x2 * 60 + y2;
            int ans = (num1 + num2) / 2;
            String ansX = Integer.toString((ans / 60));
            String ansY = Integer.toString((ans % 60));
            if (ansX.length() == 1) ansX = '0' + ansX;
            if (ansY.length() == 1) ansY = '0' + ansY;
            out.println(ansX + ":" + ansY);
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