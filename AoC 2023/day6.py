from math import sqrt
with open("AoC 2023\inputs\day6.txt", "r") as file:
    # Remove linebreaks, remove 'Blabla:' prefix, split on whitespace, and cast to int
    inp = [line.strip("\n").split(": ")[1].split() for line in file.readlines()]


def numberOfWinningChoices(times, dists):
    # Given a total time t_max, holding down the button for time t our travel distance D is
    # D = t * (t_max-t) = t*t_max - t^2
    # We wish to find t that give D(t) > D_max
    # -t^2 + t*t_max - D_max = 0 => {p = -t_max, q = D_max} => t = t_max/2 +- sqrt((t_max/2)^2 - D_max)
    output = 1
    for t_max, D_max in zip(times, dists):
        # Find both intersection points where D(t) = D_max
        lowest_win = t_max/2 - sqrt(t_max*t_max/4 - D_max)
        highest_win = t_max/2 + sqrt(t_max*t_max/4 - D_max)
        print(f"Intersect at t={lowest_win} and t={highest_win}")
        # Cast to int to get range of discrete values that solve
        # I perturb both roots slightly for the edge case where a root is exactly an integer value
        output *= (int(highest_win-1e-10) - int(lowest_win+1e-10))
    return output


times = [int(x) for x in inp[0]]
dists = [int(x) for x in inp[1]]
print("Part 1:", numberOfWinningChoices(times, dists))

time = [int("".join(inp[0]))]
dist = [int("".join(inp[1]))]
print("Part 2:", numberOfWinningChoices(time, dist))
