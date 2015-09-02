cat $1 | grep -i "bomber" | grep -i "nicolas" | grep -v "nicolasbomber" | grep '\(([0-9]\{3\})\|[0-9]\{3\}\)[ -]\?[0-9]\{3\}[ -]\?[0-9]\{4\}'
