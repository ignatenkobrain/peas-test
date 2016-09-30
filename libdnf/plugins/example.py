import gi

gi.require_version("Peas", "1.0")

from gi.repository import GObject
from gi.repository import Peas

class ExamplePlugin(GObject.Object, Peas.Activatable):
    object = GObject.Property(type=GObject.Object)

    def do_activate(self):
        print("[plugin_activate]: Python")

    def do_deactivate(self):
        print("[plugin_deactivate]: Python")
