class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not len(board) and not len(word):
            return True
        if not len(board):
            return False
        if not len(word):
            return True

        self.max_row = len(board)
        self.max_col = len(board[0])

        for row in range(0, len(board)):
            for col in range(0, len(board[row])):
                if board[row][col] == word[0]:
                    if self.parse(board, word[1:], row, col):
                        return True

        return False

    def parse(self, board, word, row, col):
        if  not len(word):
            return True
        tmp = board[row][col]
        board[row][col] = None

        if row - 1 >= 0 and board[row - 1][col] == word[0]:
            if self.parse(board, word[1:], row - 1, col):
                return True
        if row + 1 < self.max_row and board[row + 1][col] == word[0]:
            if self.parse(board, word[1:], row + 1, col):
                return True
        if col - 1 >= 0 and board[row][col - 1] == word[0]:
            if self.parse(board, word[1:], row, col - 1):
                return True
        if col + 1 < self.max_col and board[row][col + 1] == word[0]:
            if self.parse(board, word[1:], row, col + 1):
                return True
        board[row][col] = tmp
        return False