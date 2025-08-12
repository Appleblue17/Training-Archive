## H. Counter Streak

### 题目描述

In Duolingo's learning system, a *streak* represents the number of
consecutive days a user has completed at least one lesson. The platform
prominently displays streak counts and calendar tracking to motivate
consistent practice.

![image](https://uploadfiles.nowcoder.com/images/20250724/0_1753354268063/F200200AA2342EEDA99754B6C334F70D){style="width:5cm;"}A Duolingo streak.

While premium users can enjoy *Streak Freeze* (a feature that preserves
streaks when missing a day, shown as the iced days in the picture
above), free users have limited access to this functionality. For this
problem, we assume no streak freezes are available. In this case, the
only way to maintain a streak after missing a day is by utilizing the
app's time zone feature: the streak is counted using your device's local
time zone.

This means you can adjust your device's time zone before submitting a
lesson, and it will be counted according to the modified time zone. With
this feature, one could theoretically complete a lesson in "tomorrow,"
then return to "today" to submit another lesson! Since time zones range
from UTC-12 to UTC+14 ([https://en.wikipedia.org/wiki/Time
zone](https://en.wikipedia.org/wiki/Time%20zone){.uri target="_blank"}),
users in UTC+8 can adjust their clock up to $\textstyle 20$ hours backward or $\textstyle 6$ hours forward. For simplicity,
we assume that you can adjust the time zone to anywhere in between, even
non-integer time zones, instead of the list of real time zones in use.
The other factors that may affect the calculation in the real world ---
including Daylight Saving Time --- are also ignored.

Given all submission records of a user in the format
`YYYY-MM-DD HH:mm:SS` (in UTC+8 timezone), determine the maximum and
minimum possible longest streak lengths achievable by optimally
selecting time zones before each submission. The longest streak length
for a given selection of time zones is defined as the maximum number of
consecutive days where each day has at least one submission counted
between `00:00:00` and `23:59:59` (inclusive) for that day.

### 输入描述

The first line contains an integer$\textstyle n$ ($\textstyle 1 \leq n \leq 10^5$) --- the
number of submission records.

The next $\textstyle n$ lines each contain a
timestamp in the format YYYY-MM-DD HH:mm:SS (in UTC+8), guaranteed to be
in chronological order.

It is guaranteed that all dates are between 2000-01-01 and 2999-12-31.

### 输出描述

Output two space-separated integers: the maximum possible longest streak
length and the minimum possible longest streak length.

### 示例1

#### 输入

```plain
3
2020-02-29 09:10:23
2020-02-29 11:45:14
2020-02-29 12:34:58
```

#### 输出

```plain
2 1
```

### 示例2

#### 输入

```plain
3
2025-08-12 18:00:00
2025-08-12 18:00:01
2025-08-12 18:00:02
```

#### 输出

```plain
3 1
```

### 备注

For the second sample case,
- Without any modifications, the longest streak is $\textstyle 1$ day (Aug 12 2025);
- By slowing down the first submission record by $\textstyle 20$ hours (UTC-12) and
    speeding up the second submission record by $\textstyle 6$ hours (UTC+14), the
    longest streak becomes$\textstyle 3$     days (from Aug 11 2025 to Aug 13 2025).

In this problem, we use the common rules of leap year. A year is called
a *leap year* if and only if
- The year is divisible by $\textstyle 4$,
    and;
- The year is not divisible by $\textstyle 100$ unless it is also
    divisible by $\textstyle 400$.

Otherwise, the year is called a common year. For example, 2000 was a
leap year, but 1900 was a common year. The number of days in each month
is shown as the following table.
- ----------------------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- --------
         **Month**          **01**   **02**   **03**   **04**   **05**   **06**   **07**   **08**   **09**   **10**   **11**   **12**
   **Days (Common Year)**     31       28       31       30       31       30       31       31       30       31       30       31
    **Days (Leap Year)**      31       29       31       30       31       30       31       31       30       31       30       31
- ----------------------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- --------

