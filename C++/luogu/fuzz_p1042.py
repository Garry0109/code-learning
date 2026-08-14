import random, subprocess, sys

def reference(a, total):
    """Brute-force reference: process char by char, output each completed game and the final partial game."""
    w = l = 0
    res = []
    for c in a:
        if c == 'W':
            w += 1
        else:
            l += 1
        if (w >= total or l >= total) and abs(w - l) >= 2:
            res.append((w, l))
            w = l = 0
    # final partial game (only if a game was actually started and not completed)
    if w != 0 or l != 0:
        res.append((w, l))
    return res

import os
EXE = os.path.abspath('p1042_fuzz.exe')

def run_exe(a):
    inp = ''.join(a) + 'E\n'
    out = subprocess.run([EXE], input=inp.encode(),
                         capture_output=True).stdout.decode()
    return out.replace('\r\n', '\n')  # normalize Windows line endings

def format_ref(a):
    r11 = reference(a, 11)
    r21 = reference(a, 21)
    lines = []
    for (w, l) in r11:
        lines.append(f"{w}:{l}")
    lines.append("")
    for (w, l) in r21:
        lines.append(f"{w}:{l}")
    return "\n".join(lines) + "\n"

random.seed(42)
fails = 0
for trial in range(3000):
    n = random.randint(0, 40)
    a = [random.choice('WL') for _ in range(n)]
    expected = format_ref(a)
    got = run_exe(a)
    if got != expected:
        fails += 1
        print(f"FAIL seq={''.join(a)}")
        print("  expected:")
        print("   ", repr(expected))
        print("  got:")
        print("   ", repr(got))
        if fails >= 5:
            break

# Also targeted edge cases
edge_cases = [
    "W" * 11,
    "W" * 11 + "L" * 11,          # 11:0 then 0:11
    "W" * 10 + "L" * 10 + "WWW",  # deuce ending 13:10? -> 10:10,11:10,12:10 breaks? no lead2 needed
    "W" * 11 + "L",
    "W" * 12 + "L" * 10,          # 12:10 win
    "L" * 21,
    "WL" * 12,
]
for a in edge_cases:
    expected = format_ref(list(a))
    got = run_exe(list(a))
    if got != expected:
        fails += 1
        print(f"FAIL edge seq={a}")
        print("  expected:", repr(expected))
        print("  got:     ", repr(got))

print("fails =", fails)
