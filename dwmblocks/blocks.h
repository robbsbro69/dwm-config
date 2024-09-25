static const Block blocks[] = {
    /*Icon*/        /*Command*/                                       /*Update Interval*/  /*Update Signal*/
    {"💾", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 30,           0 },
    {"", "acpi -b | grep -m 1 'Battery' | awk '{print ($3 == \"Charging,\" ? \"⚡\" : \"🔋\") \" \"$4}' | tr -d ','", 60, 0 },
    {"☀️", "brightnessctl get | awk '{print $1}'", 1, 0},
    {"🔊", "amixer get Master | awk -F'[][]' 'END{ print $2 }'", 1, 0},
    {"", "ifstat -i wlp4s0 1 1 | awk 'NR==3 {print \"⬇️\" $1 \" KB/s ⬆️\" $2 \" KB/s\"}'", 5, 0 },
    {"📅", "date '+%b %d (%a) %I:%M%p'", 5, 0 },
};

static char delim[] = " | ";
static unsigned int delimLen = 5;

