#!/bin/sh

sudo cat /var/log/daemon.log | grep -a 'MAN-DAEMON-LOGGER'
