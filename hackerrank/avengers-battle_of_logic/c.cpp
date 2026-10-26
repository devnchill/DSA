#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shortestPath' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY grid as parameter.
 */

int shortestPath(vector<string> grid) {
  int n = grid.size();
  int m = grid[0].size();
  int sx = -1, sy = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'S') {
        sx = i;
        sy = j;
      }
    }
  }
  queue<tuple<int, int, int, int>> q;
  vector<vector<vector<bool>>> visited(
      n, vector<vector<bool>>(m, vector<bool>(2, false)));
  q.push({sx, sy, 0, 0});
  visited[sx][sy][0] = true;

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  while (!q.empty()) {
    auto [x, y, broken, dist] = q.front();
    q.pop();

    if (grid[x][y] == 'E')
      return dist;
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;

      if (grid[nx][ny] == '#') {
        if (broken == 0 && !visited[nx][ny][1]) {
          visited[nx][ny][1] = true;
          q.push({nx, ny, 1, dist + 1});
        }
      } else {
        if (!visited[nx][ny][broken]) {
          visited[nx][ny][broken] = true;
          q.push({nx, ny, broken, dist + 1});
        }
      }
    }
  }
  return -1;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int rows = stoi(first_multiple_input[0]);

  int cols = stoi(first_multiple_input[1]);

  vector<string> grid(rows);

  for (int i = 0; i < rows; i++) {
    string grid_item;
    getline(cin, grid_item);

    grid[i] = grid_item;
  }

  int result = shortestPath(grid);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
