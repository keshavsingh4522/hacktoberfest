# This File is all about creating and training efficien-net versions on cpu and gpu

import tensorflow as tf
import os
import yaml
import sys
#from tf.keras.applications import EfficientNetB0
from efficientnet.keras import EfficientNetB1

# from PIL import ImageFile
# ImageFile.LOAD_TRUNCATED_IMAGES = True


with open(sys.argv[1]) as file:
    hyperparameters = yaml.load(file, Loader = yaml.FullLoader)


print('==================================================================================================')
for p in hyperparameters:
    print(str(p) + " = " + str(hyperparameters[p]))
print('==================================================================================================')


gpu_devices = hyperparameters['gpu_devices']
classes = hyperparameters['classes']
train_data_dir = hyperparameters['train_data_dir']
batch_size = hyperparameters['batch_size']
interpolation = hyperparameters['interpolation']
valid_data_dir = hyperparameters['valid_data_dir']
learning_rate = hyperparameters['learning_rate']
patience = hyperparameters['patience']
epochs = hyperparameters['epochs']
weights_folder = hyperparameters['weights_folder']
retrain_model = hyperparameters['retrain_model']


os.environ["CUDA_DEVICE_ORDER"] = "PCI_BUS_ID";
os.environ["CUDA_VISIBLE_DEVICES"] = gpu_devices;


lrbs = 'lr' + str(learning_rate) + '_bs' + str(batch_size) 
logdir = os.path.join('weights', weights_folder, lrbs, 'logdir')
checkpoints_filepath = os.path.join('weights', weights_folder, lrbs, 'model_{epoch:02d}_{val_accuracy:.05f}.h5')
path_to_save_final_model = os.path.join('weights', weights_folder, lrbs, 'final.h5')
final_epoch_saved_model = os.path.join('weights', weights_folder, lrbs, 'final_epoch')
if not os.path.exists(logdir):
    os.makedirs(logdir)
if not os.path.exists(final_epoch_saved_model):
    os.makedirs(final_epoch_saved_model)


##model
def model_architecture():
    input_shape = (240, 240, 3)
    input_tensor = tf.keras.layers.Input(shape = input_shape)
    # base_model = tf.keras.applications.EfficientNetB0(include_top = False, weights = 'imagenet')
    base_model = EfficientNetB1(include_top=False, weights='imagenet', input_tensor=input_tensor)
    global_avg = tf.keras.layers.GlobalAveragePooling2D()(base_model.output)
    # global_max = tf.keras.layers.GlobalMaxPooling2D()(base_model.output)
    # final_dense = tf.keras.layers.Dense(classes, activation = 'softmax')(global_max)
    # # dropout_1 = tf.keras.layers.Dropout(0.3)(global_avg)
    dense_1 = tf.keras.layers.Dense(20, activation = 'relu')(global_avg)
    dropout_2 = tf.keras.layers.Dropout(0.3)(dense_1)
    dense_2 = tf.keras.layers.Dense(10, activation = 'relu')(dropout_2)
    # dense_3 = tf.keras.layers.Dense(classes, activation = 'softmax')(dense_2)
    dense_3 = tf.keras.layers.Dense(classes, activation = 'sigmoid')(dense_2)
    model = tf.keras.models.Model(inputs = base_model.inputs, outputs = dense_3)
    # model = tf.keras.models.Model(inputs = base_model.inputs, outputs = final_dense)

    return model
    
strategy = tf.distribute.MirroredStrategy(["GPU:0", "GPU:1", "GPU:2", "GPU:3"])
with strategy.scope():
    if retrain_model == 'F':
        model = model_architecture()
    else:
        model = tf.keras.models.load_model(retrain_model)
model.summary()


datagen = tf.keras.preprocessing.image.ImageDataGenerator(rescale = 1./255)


#Data Generator
train_generator = datagen.flow_from_directory(
    directory = train_data_dir, target_size = (224, 224),
    classes = ['real', 'fake'], class_mode = 'binary', batch_size = batch_size, interpolation = interpolation)
validation_generator = datagen.flow_from_directory(
    directory = valid_data_dir, target_size = (224, 224),
    classes = ['real', 'fake'], class_mode = 'binary', batch_size = 1, interpolation = interpolation)


#Optimizer
optimizer = tf.keras.optimizers.Adam(learning_rate=learning_rate)


# model.compile(loss = 'categorical_crossentropy', optimizer = optimizer, metrics = ['accuracy', 'categorical_accuracy'])
model.compile(loss = 'binary_crossentropy', optimizer = optimizer, metrics = ['accuracy'])
    

checkpoint = tf.keras.callbacks.ModelCheckpoint(
    checkpoints_filepath, monitor = 'val_accuracy',
    verbose = 1, save_best_only=True, mode='max')
early_stopping = tf.keras.callbacks.EarlyStopping(
    monitor='val_accuracy', min_delta=0, patience=patience,
    verbose = 1, mode = 'max', baseline = None, restore_best_weights = True)
tensorboard_callback = tf.keras.callbacks.TensorBoard(log_dir = logdir)


callbacks_list = [checkpoint, early_stopping, tensorboard_callback]
# callbacks_list = [early_stopping, tensorboard_callback]



training = model.fit(
    x = train_generator,
    batch_size = batch_size,
    epochs = epochs,
    verbose = 1,
    validation_data = validation_generator,
    callbacks = callbacks_list,
    workers = 8,
    shuffle = True)


model.save(path_to_save_final_model)

#Additional Saving Strategies:::
tf.keras.models.save_model(model, final_epoch_saved_model, save_format = 'tf')
# tf.keras.models.save_model(model, os.path.join('weights', weights_folder, lrbs, 'final.h5'), save_format='h5')
