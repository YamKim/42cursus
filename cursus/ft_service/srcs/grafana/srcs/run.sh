#!/bin/sh

/usr/sbin/telegraf/telegraf &
cd /usr/share/grafana/bin/ && ./grafana-server
