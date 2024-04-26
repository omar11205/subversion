def add_time(start_time, time_add, start_day=''):
    # deconstructing start_time
    hard_time,  day_mode = start_time.split(' ')
    hours, minutes = hard_time.split(':')

    # deconstructing time_add
    hours_add, minutes_add = time_add.split(':')

    # convert to integers
    hours = int(hours)
    minutes = int(minutes)
    hours_add = int(hours_add)
    minutes_add = int(minutes_add)

    # days later counter
    days_later = []

    # time output string
    output = []

    if (hours_add > 0) or (minutes_add > 0):
        res_minutes = minutes + minutes_add
        res_hours = hours + hours_add
        if res_minutes >= 60:
            res_minutes = res_minutes - 60
            res_hours += 1
        if res_hours == 12 and day_mode == 'AM':
            days_later = 'PM'
        if (res_hours > 12) and (day_mode == 'AM'):
            res_hours = res_hours - 12
            day_mode = 'PM'
        if (res_hours > 12) and (day_mode == 'PM'):
            res_hours = res_hours - 12
            days_later += 1
            day_mode = 'AM'
        if days_later == 1:
            output = f'{res_hours}:{res_minutes} {day_mode} (next day)'
        if days_later > 1:
            output = f'{res_hours}:{res_minutes} ({days_later} days later)'
        output = f'{res_hours}:{res_minutes} {day_mode}'
    else:
        output = f'{hours}:{minutes} {day_mode}'

    print(output)


add_time('11:30 AM', '00:30')

