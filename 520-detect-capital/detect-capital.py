class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        while True:
            if word == word.upper():
                return True
                break
            elif word == word.lower():
                return True
                break
            elif word == word.capitalize():
                return True
                break
            else:
                return False
                break
