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
        CSmallestWord solver = new CSmallestWord();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSmallestWord {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            char[] a = StringAlgorithm.toCharArray(in.nextString(), 1);
            int n = a.length - 1;
            int r = n + 1;
            boolean[] ch = new boolean[n + 1];
            while (r >= 1) {
                int curMin = 'z';
                int pos = 0;
                for (int i = 1; i <= r - 1; i++) {
                    if (a[i] <= curMin) {
                        curMin = a[i];
                        pos = i;
                    }
                }
                if (pos == 0) break;
                ch[pos] = true;
                r = pos;
            }
            int[] ans = new int[n + 1];
            for (int i = n; i >= 1; i--) {
                if (ch[i]) {
                    ans[i] = 1;
                    int cur = i - 1;
                    while (ch[cur])
                        cur--;
                    if (cur != 0) ans[cur] = 1;
                    i = cur;

                }
            }
            for (int i = 1; i <= n; i++) {
                out.print(ans[i] + " ");
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

    static class StringAlgorithm {
        public static char[] toCharArray(String s, int stIndex) {
            char[] result = new char[s.length() + stIndex];
            for (int i = 0; i < s.length(); i++) {
                result[i + stIndex] = s.charAt(i);
            }
            return result;
        }

    }
}