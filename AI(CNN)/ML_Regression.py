import numpy as np
import tensorflow as tf
from tensorflow import keras
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import pandas as pd

data = pd.read_csv("/content/ALL_X_train_p.csv")
ydata = pd.read_csv("/content/ALL_y_train_p.csv")
ydata = ydata.drop("Unnamed: 0", axis="columns")
data = data.drop("Unnamed: 0", axis="columns")

scaler = StandardScaler()
data_scaled = scaler.fit_transform(data)

model = keras.Sequential([
    keras.layers.Input(shape=(8,)),
    keras.layers.Dense(512, activation='relu', kernel_regularizer=keras.regularizers.l2(0.01)),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.5),
    keras.layers.Dense(256, activation='relu', kernel_regularizer=keras.regularizers.l2(0.01)),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.4),
    keras.layers.Dense(128, activation='relu', kernel_regularizer=keras.regularizers.l2(0.01)),
    keras.layers.BatchNormalization(),
    keras.layers.Dropout(0.3),
    keras.layers.Dense(64, activation='relu', kernel_regularizer=keras.regularizers.l2(0.01)),
    keras.layers.BatchNormalization(),
    keras.layers.Dense(32, activation='relu', kernel_regularizer=keras.regularizers.l2(0.01)),
    keras.layers.BatchNormalization(),
    keras.layers.Dense(16, activation='relu', kernel_regularizer=keras.regularizers.l2(0.01)),
    keras.layers.BatchNormalization(),
    keras.layers.Dense(12, activation='softmax')
])
lr_schedule = keras.optimizers.schedules.ExponentialDecay(
    initial_learning_rate=0.0001,
    decay_steps=1500,
    decay_rate=0.9)

custom_optimizer = keras.optimizers.Adam(learning_rate=lr_schedule)
model.compile(optimizer=custom_optimizer,
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

early_stopping = keras.callbacks.EarlyStopping(monitor='val_loss', patience=200, restore_best_weights=True)
model.fit(data_scaled, ydata, epochs=500, batch_size=128, validation_split=0.2, callbacks=[early_stopping])

xdatat = pd.read_csv("/content/ALL_X_test_p.csv")
xdatat = xdatat.drop("Unnamed: 0", axis="columns")
xdatat_scaled = scaler.transform(xdatat)
ydatat = pd.read_csv("/content/ALL_y_test_p.csv")
ydatat = ydatat.drop("Unnamed: 0", axis="columns")

test_loss, test_accuracy = model.evaluate(xdatat_scaled, ydatat)
print(f"Test Accuracy: {test_accuracy * 100:.2f}%")

model.save_weights("/content/model_w.h5")



