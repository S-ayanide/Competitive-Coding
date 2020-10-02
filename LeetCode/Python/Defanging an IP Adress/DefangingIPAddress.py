class Solution:
    def defangIPaddr(self, address: str) -> str:
        # replace
        return address.replace('.', '[.]')