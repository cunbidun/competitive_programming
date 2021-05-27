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
        C2IncreasingSubsequenceHardVersion solver = new C2IncreasingSubsequenceHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class C2IncreasingSubsequenceHardVersion {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int lPos = 1;
            int rPos = n;
            ArrayList<Character> ans = new ArrayList<>();
            int curVal = 0;
            while (lPos <= rPos) {
                if (a[lPos] < curVal && a[rPos] < curVal) break;
                if (a[lPos] == a[rPos]) {
                    int cnt1 = 1;
                    int cnt2 = 1;
                    for (int i = lPos + 1; i <= rPos; i++) {
                        if (a[i] > a[i - 1]) cnt1++;
                        else break;
                    }
                    for (int i = rPos - 1; i >= lPos; i--) {
                        if (a[i] > a[i + 1]) cnt2++;
                        else break;
                    }
                    if (cnt1 > cnt2) {
                        for (int i = 1; i <= cnt1; i++) ans.add('L');
                    } else for (int i = 1; i <= cnt2; i++) ans.add('R');

                    break;
                }
                if (a[lPos] < a[rPos]) {
                    if (a[lPos] > curVal) {
                        ans.add('L');
                        curVal = a[lPos];
                        lPos++;
                        continue;
                    }
                    curVal = a[rPos];
                    ans.add('R');
                    rPos--;
                } else {
                    if (a[rPos] > curVal) {
                        curVal = a[rPos];
                        ans.add('R');
                        rPos--;
                        continue;
                    }
                    ans.add('L');
                    curVal = a[lPos];
                    lPos++;
                }
            }
            out.println(ans.size());
            for (char c : ans) out.print(c);
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}