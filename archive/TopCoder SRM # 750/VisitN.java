package Code;

public class VisitN {
    boolean[][] visited = new boolean[30][30];

    public String visit(int n, int r, int c) {
        n--;
        visited[r][c] = true;
        String ans = "";
        if (n == 0) {
            System.out.println(ans.length());
            return ans;
        }

        for (int i = r; i >= 0; i--) {
            r--;
            if(r < 0) break;
            ans += "N";
            if (!visited[r][c]) {
                n--;
                visited[r][c] = true;
            }
            if (n == 0) {
                System.out.println(ans.length());
                return ans;
            }
        }
        r = 0;
        for (int i = c; i >= 0; i--) {
            c--;
            if(c < 0) break;
            ans += "W";
            if (!visited[r][c]) {
                n--;
                visited[r][c] = true;
            }
            if (n == 0) {
                System.out.println(ans.length());
                return ans;
            }
        }
        c = 0;
        while (r < 30) {
            for (int i = 0; i <= 29; i++) {
                if (c != 29) {
                    c++;
                    ans += "E";
                    if (!visited[r][c]) {
                        n--;
                        visited[r][c] = true;
                    }
                    if (n == 0) {
                        System.out.println(ans.length());
                        return ans;
                    }
                } else {
                    r++;
                    if (r == 30) break;
                    ans += "S";
                    if (!visited[r][c]) {
                        n--;
                        visited[r][c] = true;
                    }
                    if (n == 0){
                        System.out.println(ans.length());
                        return ans;
                    }
                }
            }

            for (int i = 0; i <= 29; i++) {
                if (c != 0) {
                    c--;
                    ans += "W";
                    if (!visited[r][c]) {
                        n--;
                        visited[r][c] = true;
                    }
                    if (n == 0) {
                        System.out.println(ans.length());
                        return ans;
                    }
                } else {
                    r++;
                    if (r == 30) break;
                    ans += "S";
                    if (!visited[r][c]) {
                        n--;
                        visited[r][c] = true;
                    }
                    if (n == 0) {
                        System.out.println(ans.length());
                        return ans;
                    }
                }
            }
        }
        return ans;
    }


}
