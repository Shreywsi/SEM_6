def smart_home_lighting(hour, num_people):

    if num_people == 0:
        return "Lights OFF (No one at home)"

    if hour >= 23:
        return "Lights OFF (After 11:00 PM)"

    if hour == 6:
        return "Lights ON (DIM mode - Morning)"

    if 6 < hour < 18:
        return "Lights ON (DIM mode - Daytime)"
    else:
        return "Lights ON (BRIGHT mode - Nighttime)"

hour = int(input("Enter current hour (24hr time): "))
people = int(input("Enter number of people at home: "))

result = smart_home_lighting(hour, people)
print(result)
