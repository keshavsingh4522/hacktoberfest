from flask_wtf import FlaskForm
from flask_wtf.file import FileField, FileAllowed
from wtforms import StringField, SubmitField, BooleanField, PasswordField, RadioField, TextAreaField
from wtforms.validators import Length, EqualTo, Email, DataRequired, ValidationError, Regexp
from flask_login import current_user
from Sakha.models import User



class RegistrationForm(FlaskForm):
    firstname =  StringField('Firstname', validators=[DataRequired(), Length(max=30, message='should be atmost 30 characters long'),
                                                     Regexp(r'^[a-zA-Z\s]+$' ,message = 'name should contain only alphabats')])
    lastname =  StringField('Lastname', validators=[DataRequired(), Length(max=30, message='should be atmost 30 characters long')
                                                    , Regexp(r'^[a-zA-Z\s]+$' ,message = 'name should contain only alphabats')])
    username = StringField('Username', validators=[DataRequired(), Length(min=5, max=30, message='username should be atleast 5 characters long'),
                                                    Regexp(r'^[a-zA-Z0-9]+$' ,message = 'username should contain only alphabats and numbers')])
    email = StringField('Email Address', validators=[DataRequired(), Email(message='email  address should be valid')])
    gender = RadioField('Gender', choices=[('Female', 'Female'), ('Male', 'Male'), ('Others', 'Others')], validators=[DataRequired()])
    password = PasswordField('Password', validators=[DataRequired(), Length(min=8, max=100, message='password should be atleast 8 characters long')])
    reenter_password = PasswordField('Reenter Password', validators=[EqualTo('password', message='reentered password should be similar to password')])
    submit = SubmitField('Create New Account')


    def validate_username(self, username):
        user = User.query.filter_by(username=username.data).first()
        if user:
            raise ValidationError('username is already taken, try different one')

    def validate_email(self,email):
        user = User.query.filter_by(email=email.data).first()
        if user:
            raise ValidationError('email address is already registerd, try different one')
        
    def validate_password(self, password):
        specialCharacters = '!@#$%^&*()_+-={}[]|\\:;\'"?/>.<,~`'
        specialTotal = 0
        for char in password.data:
            if char in specialCharacters:
                specialTotal += 1
        if not specialTotal:
            raise ValidationError('password should contain one or more special characters')




class LoginForm(FlaskForm):
    email = StringField('Email Address', validators=[DataRequired(), Email(message='email  address should be valid')])
    password = PasswordField('Password', validators=[DataRequired(), Length(min=8, max=100, message='password should be atleast 8 characters long')])
    remember = BooleanField('Remember me')
    submit = SubmitField('Login Folk')




class NameUpdateForm(FlaskForm):
    firstname =  StringField('Firstname', validators=[DataRequired()])
    lastname =  StringField('Lastname', validators=[DataRequired()])
    submit = SubmitField('Save')




class AboutUpdateForm(FlaskForm):
    address = StringField('Address')
    about_user = TextAreaField('About Me')
    submit = SubmitField('Save')




class UniqueDetailsUpdateForm(FlaskForm):
    username = StringField('Username', validators=[DataRequired(), Length(min=5, max=30, message='username should be atleast 5 characters long'),
                                                    Regexp(r'^[a-zA-Z0-9]+$' ,message = 'username should contain only alphabats and numbers')])
    email = StringField('Email Address', validators=[DataRequired(), Email(message='email  address should be valid')])
    submit = SubmitField('Save')


    def validate_username(self, username):
        if current_user.username != username.data:
            user = User.query.filter_by(username=username.data).first()
            if user:
                raise ValidationError('username is already taken, try different one')

    def validate_email(self,email):
        if current_user.email != email.data:
            user = User.query.filter_by(email=email.data).first()
            if user:
                raise ValidationError('email address is already registerd, try different one')




class UploadAvatarForm(FlaskForm):
    profile_pic=FileField('Profile Image', validators=[FileAllowed(['jpg','png','gif','svg', 'jpeg'],
                                                                 message='Image with extension jpg/png/gif/svg is only allowed')])
    header_pic = FileField('Header Image', validators=[FileAllowed(['jpg','png','gif','svg', 'jpeg'],
                                                        message='Image with extension jpg/png/gif/svg is only allowed')])
    submit = SubmitField('Upload')




class CreatePostForm(FlaskForm):
    content=TextAreaField('Content', validators=[Length(max = 5000, message = 'Upto 5000 characters are allowed')])
    postImage = FileField('Upload Image', validators=[FileAllowed(['jpg','png','gif','svg', 'jpeg'],
                                                        message = 'Image with extension jpg/png/gif/svg is only allowed')])
    submit = SubmitField('Post')