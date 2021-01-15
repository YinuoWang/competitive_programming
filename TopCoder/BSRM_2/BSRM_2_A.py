class FriendFinder:
    def distance(self, line):
        S_location, F_location = -1, -1
        for i, char in enumerate(line):
            if char == "S":
                S_location = i
            elif char == "F":
                F_location = i

        return abs(F_location-S_location)