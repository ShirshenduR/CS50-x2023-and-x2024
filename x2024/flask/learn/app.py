from flask import Flask, render_template, request
app=Flask(__name__)


@app.route("/")
def index():
    name = request.args.get("name", "World")
    return render_template("index.html", name=name)


@app.route("/submit")
def submit():
    name = request.args.get("name", "World")
    return render_template("submit.html", name=name)
