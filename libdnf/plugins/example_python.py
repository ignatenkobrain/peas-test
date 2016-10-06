import gi

gi.require_version("Dnf", "2.0")

from gi.repository import GObject
from gi.repository import Dnf

class ExamplePlugin(GObject.Object, Dnf.Activatable):

    def do_activate(self):
        print("[plugin_activate]: Python")

    def do_deactivate(self):
        print("[plugin_deactivate]: Python")

    def do_run(self, ctx):
        print("Worked: Python!")
