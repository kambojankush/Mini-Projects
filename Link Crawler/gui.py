import tkinter as tk
import tkinter.messagebox


class App:

    def __init__(self, master):
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

        # **** Status Bar ****
        self.status = tk.Label(self.bottom_frame, text="Ready to grab links...", bd=1, relief="sunken", anchor="w")
        self.status.pack(fill="x")

        # **** Top Frame ****
        self.name_label = tk.Label(self.top_frame, text="Project Name:")
        self.name_label.grid(row=0, column=0, sticky="e", pady=30, padx=10)

        self.name_entry = tk.Entry(self.top_frame)
        self.name_entry.grid(row=0, column=1, pady=30)

        self.url_label = tk.Label(self.top_frame, text="Homepage:")
        self.url_label.grid(row=1, column=0, sticky="e", padx=10)

        self.url_entry = tk.Entry(self.top_frame)
        self.url_entry.grid(row=1, column=1)

        self.button1 = tk.Button(self.top_frame, text="Grab")
        self.button1.grid(row=2, columnspan=2, pady=50)

    @staticmethod
    def show_about():
        tk.messagebox.showinfo('About',
                               'This project grabs and saves all the links of a domain present within the given '
                               'homepage and also the links found within those links!')

    def get_project_name(self):
        return str(self.name_entry.get())

    def get_homepage(self):
        return str(self.url_entry.get())


def main():
    root = tk.Tk()
    root.tk.call('tk', 'scaling', 3.0)
    root.title('Link Grabber')
    root.option_add("*Font", "15")
    root.option_add('*Dialog.msg.font', 'Helvetica 10')

    root.geometry("700x350")
    root.resizable(0, 0)

    App(root)

    root.mainloop()


if __name__ == '__main__':
    main()
