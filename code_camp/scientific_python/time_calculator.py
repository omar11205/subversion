
def add_time(start, duration, start_day=None):
    # Parsing start time
    start_time, period = start.split()
    start_hour, start_minute = map(int, start_time.split(':'))
    start_hour = start_hour if period == 'AM' else start_hour + 12

    # Parsing duration
    duration_hour, duration_minute = map(int, duration.split(':'))

    # Calculating new time
    new_hour = (start_hour + duration_hour + (start_minute + duration_minute) // 60) % 24
    new_minute = (start_minute + duration_minute) % 60
    days_passed = (start_hour + duration_hour + (start_minute + duration_minute) // 60) // 24

    # Determining period (AM/PM)
    new_period = 'AM' if new_hour < 12 else 'PM'
    if new_hour >= 12:
        new_hour -= 12
    if new_hour == 0:
        new_hour = 12

    # Constructing new_time string
    new_time = f"{new_hour:02}:{new_minute:02} {new_period}"

    # Handling days later
    if days_passed == 1:
        new_time += " (next day)"
    elif days_passed > 1:
        new_time += f" ({days_passed} days later)"

    # Handling start_day parameter
    if start_day:
        start_day = start_day.capitalize()
        days_of_week = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
        start_index = days_of_week.index(start_day)
        new_day_index = (start_index + days_passed) % 7
        new_day = days_of_week[new_day_index]
        new_time += f", {new_day}"

    new_time = str(new_time)
    return new_time


print(add_time('3:30 PM', '2:12'))  # Should return '5:42 PM'
add_time('11:55 AM', '3:12')  # Should return '3:07 PM'
