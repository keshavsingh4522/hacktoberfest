from datetime import datetime
from flask_login import UserMixin
from Sakha import db, login_manager




@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))



followers = db.Table('followers',
            db.Column('follower_id', db.Integer, db.ForeignKey('users.id')),
            db.Column('followed_id', db.Integer, db.ForeignKey('users.id'))
        )


  
class PostLike(db.Model):
    __tablename__='postlikes'
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('users.id'))
    post_id = db.Column(db.Integer, db.ForeignKey('posts.id'))



class User(UserMixin, db.Model):
    __tablename__="users"
    id = db.Column(db.Integer, primary_key=True)
    firstname = db.Column(db.String(30), nullable=False)
    lastname = db.Column(db.String(30), nullable=False)
    username = db.Column(db.String(30), nullable=False, unique=True)
    email = db.Column(db.String(100), nullable=False, unique=True)
    gender = db.Column(db.Text, nullable=False)
    account_date = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)
    password = db.Column(db.String(100), nullable=False)
    address = db.Column(db.String(200))
    dob = db.Column(db.DateTime)
    about_user = db.Column(db.Text)
    profile_pic = db.Column(db.String(100), nullable=False, default='default.png')
    header_pic = db.Column(db.String(100), nullable=False, default='header.jpg')
    post = db.relationship('Post', backref='author', lazy='dynamic')
    followed = db.relationship('User', secondary='followers',
                            primaryjoin = (followers.c.follower_id == id),
                            secondaryjoin = (followers.c.followed_id == id),
                            backref = db.backref('followers', lazy='dynamic'), lazy='dynamic')
    liked = db.relationship('PostLike', backref='user', lazy='dynamic')


    def __repr__(self):
        return f'User({self.firstname}, {self.address}, {self.about_user})'


    def follow(self,user):
        if not self.is_following(user):
            self.followed.append(user)

    def unfollow(self, user):
        if self.is_following(user):
            self.followed.remove(user)

    def is_following(self,user):
        return self.followed.filter(
                followers.c.followed_id == user.id).count() == 1



    def like_post(self, post):
        if not self.has_liked(post):
            like = PostLike(user_id=self.id, post_id=post.id)
            db.session.add(like)
    
    def unlike_post(self, post):
        if self.has_liked(post):
            PostLike.query.filter_by(user_id=self.id,post_id=post.id).delete()

    def has_liked(self, post):
        return PostLike.query.filter_by(user_id=self.id, post_id=post.id).count() == 1
    




class Post(db.Model):
    __tablename__ = "posts"
    id = db.Column(db.Integer, primary_key=True)
    content = db.Column(db.Text)
    postImage = db.Column(db.String(100))
    postDate = db.Column(db.DateTime, default=datetime.utcnow)
    userId = db.Column(db.Integer, db.ForeignKey('users.id'), nullable=False)
    likes = db.relationship('PostLike',backref='post', lazy='dynamic')