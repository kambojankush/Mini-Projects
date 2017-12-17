import tkinter as tk
import tkinter.messagebox
import tkinter.scrolledtext as tkst
import sys
import validators
from domain import *
from main import *


class StdRedirector:
    def __init__(self, text_widget):
        self.text_space = text_widget

    def write(self, string):
        self.text_space.config(state=tk.NORMAL)
        self.text_space.insert("end", string)
        self.text_space.see("end")
        self.text_space.config(state=tk.DISABLED)


class App:

    def __init__(self, master):
        # HiDPI Scaling
        master.tk.call('tk', 'scaling', 3.0)

        # configuration
        master.title('Link Grabber')
        master.option_add("*Font", "15")
        master.option_add('*Dialog.msg.font', 'Helvetica 10')

        master.geometry("1100x850")
        master.resizable(0, 0)

        # **** Menu Bar ****
        self.menu = tk.Menu(master)
        master.config(menu=self.menu)

        self.file_menu = tk.Menu(self.menu)
        self.menu.add_cascade(label="File", menu=self.file_menu)
        self.file_menu.add_command(label="About", command=self.show_about)
        self.file_menu.add_command(label="Quit", command=master.quit)

        # **** Frames ****
        self.top_frame = tk.Frame(master)
        self.top_frame.pack(fill="both", side="top", anchor="center")

        self.bottom_frame = tk.Frame(master)
        self.bottom_frame.pack(side="bottom", fill="x")

        self.stringvar1 = tk.StringVar(self.top_frame)
        self.stringvar2 = tk.StringVar(self.top_frame)

        self.stringvar1.trace("w", self.enable)
        self.stringvar2.trace("w", self.enable)
        # **** Status Bar ****
        self.status = tk.Label(self.bottom_frame, text="Ready to grab links...", bd=1, relief="sunken", anchor="w")
        self.status.pack(fill="x")

        # **** Top Frame ****
        self.name_label = tk.Label(self.top_frame, text="Project Name:")
        self.name_label.grid(row=0, column=0, sticky="e", pady=30, padx=10)

        self.name_entry = tk.Entry(self.top_frame, width=30, textvariable=self.stringvar1)
        self.name_entry.grid(row=0, column=1, pady=30)

        self.url_label = tk.Label(self.top_frame, text="Homepage:")
        self.url_label.grid(row=1, column=0, sticky="e", padx=10)

        self.url_entry = tk.Entry(self.top_frame, fg="blue", width=30, textvariable=self.stringvar2)
        self.url_entry.grid(row=1, column=1)

        self.btn_text = tk.StringVar()
        self.button1 = tk.Button(self.top_frame, textvariable=self.btn_text, fg="green", state="disabled", command=lambda: grab(self))
        self.btn_text.set("Grab")
        self.button1.grid(row=2, columnspan=2, pady=50)

        self.text = tkst.ScrolledText(self.top_frame, height=12, width=52, relief="sunken", bg="grey", fg="white")
        self.text.grid(row=3, columnspan=2, padx=25)
        self.text.insert(tk.END, 'Queued = 0 | Grabbed = 0\n')

        sys.stdout = StdRedirector(self.text)
        sys.stderr = StdRedirector(self.text)

    @staticmethod
    def show_about():
        tk.messagebox.showinfo('About',
                               'This project grabs and saves all the links of a domain present within the given '
                               'homepage and also the links found within those links!')

    def get_project_name(self):
        return str(self.name_entry.get())

    def get_homepage(self):
        return str(self.url_entry.get())

    # enable a button if both the Entry fields are not empty
    def enable(self, *args):
        x = self.stringvar1.get()
        y = self.stringvar2.get()
        if x and validators.url(y):
            self.button1.config(state='normal')
        else:
            self.button1.config(state='disabled')


def grab(app):
    app.btn_text.set("Grabbing")
    app.button1.config(state="disabled")
    project_name = app.get_project_name()
    homepage = app.get_homepage()
    domain_name = get_domain_name(homepage)
    queued_file = project_name + '/queue.txt'
    crawled_file = project_name + '/crawled.txt'
    no_of_threads = 8
    app.status["text"] = 'Grabbing....'
    Spider(project_name, homepage, domain_name)
    create_workers(no_of_threads)
    crawl(queued_file)
    print('Completed')
    app.status["text"] = 'Completed.'
    app.btn_text.set("Grab")
    app.button1.config(state="normal")

def main():
    root = tk.Tk()

    app = App(root)

    root.mainloop()


if __name__ == '__main__':
    main()
