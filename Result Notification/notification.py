import gi
gi.require_version('Notify', '0.7')
from gi.repository import Notify


def generate_notification(message, summary=''):

    if message == '':
        pass
    else:
        Notify.init("Results")
        notification = Notify.Notification.new(message, summary)
        notification.show()